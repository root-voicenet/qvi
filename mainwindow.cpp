#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qfiledialog.h"
#include "QResizeEvent"
#include "qmessagebox.h"
#include "loadfolderthread.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass), m_site(NULL)
{
    angle = 0;
    ui->setupUi(this);
    currentDirectory = QDir::homePath();
    imageListModel.invisibleRootItem()->setColumnCount(1);
    ui->listView->setModel(&imageListModel);


    QFile file(":/taxonomy.txt");
    file.open(QIODevice::ReadOnly);
    QString str = file.readAll();
    pointerModel.init(str.split("\n"));
    file.close();


    m_site = new Connector("http://test.irkipedia.ru/api");
    connect(m_site, SIGNAL(pointersLoaded()), this, SLOT(pointerLoaded()));
    m_site->Login("admin", "alcd7c9");

    ui->imageLabel->addMenuItem(ui->actionFit_to_screen);
    ui->imageLabel->addMenuItem(ui->actionFullscreen);
    ui->imageLabel->addMenuItem(ui->actionHide_Listbox);
    ui->imageLabel->addMenuItem(ui->actionNext);
    ui->imageLabel->addMenuItem(ui->actionPrev);
    ui->imageLabel->addMenuItem(ui->actionRotate_Clockwise);
    ui->imageLabel->addMenuItem(ui->actionRotate_Counter_Clockwise);
    connect(&loadFolderThread, SIGNAL( setupProgressDialog(int) ), this, SLOT( setupProgressDialog(int) ));
    connect(&loadFolderThread, SIGNAL( updateProgressDialog() ), this, SLOT( updateProgressDialog() ));
    connect(&loadFolderThread, SIGNAL( finished() ), this, SLOT( endOfFolderLoad() ));
    connect(&loadFolderThread, SIGNAL( addImageItem(QString) ), this, SLOT ( addImageItem(QString) ),Qt::QueuedConnection);
}

MainWindow::~MainWindow()
{
    if(m_site) delete m_site;
    delete ui;
}

void MainWindow::on_actionOpenFile_triggered()
{
    QString newImageName = QFileDialog::getOpenFileName(this,
    tr("Open File"), "", tr("lists (*.jpg *.gif *.png )"));
    if(!newImageName.isEmpty()){
        imageList.clear();       //clear the listView because were not adding the image, It replacing
        imageListModel.clear();  //''
        imageList.append(newImageName);
        addImageItem(newImageName);
        imageName = newImageName;
        draw();
    }
}

void MainWindow::on_actionAdd_file_triggered()
{
    QString newImageName = QFileDialog::getOpenFileName(this,
    tr("Open File"), "", tr("lists (*.jpg *.gif *.png )"));
    if(!newImageName.isEmpty()){
        imageList.append(newImageName);
        imageName = QDir::toNativeSeparators(newImageName);
        addImageItem(newImageName);
        draw();
    }
}


void MainWindow::on_actionOpen_folder_triggered()
{
    QString newDirectory = QFileDialog::getExistingDirectory(this,
    tr("Open Folder"), currentDirectory, QFileDialog::DontResolveSymlinks | QFileDialog::ShowDirsOnly);
    if(!newDirectory.isEmpty()){
        currentDirectory.clear();
        currentDirectory.append(newDirectory);
        imageList.clear();
        imageListModel.clear();
        ui->imageLabel->clear();
        ui->listView->setModel(new QStandardItemModel());
        //the rest is now in a thread
        loadFolderThread.setValues(currentDirectory);
        loadFolderThread.start();
    }
}

void MainWindow::setupProgressDialog(int numFiles)
{
    progress.setLabelText("Loading Images");
    progress.setCancelButtonText("Abort Load");
    progress.setMinimum(0);
    progress.setMaximum(numFiles);
    progress.setParent(this);
    progress.setWindowModality(Qt::ApplicationModal);
    connect(&progress, SIGNAL(canceled()), &loadFolderThread, SLOT(stop()) );
    progress.exec();
}

void MainWindow::updateProgressDialog()
{
    progress.setValue(progress.value()+1);
}

void MainWindow::endOfFolderLoad()
{
    ui->listView->setModel(&imageListModel);
    this->imageList = loadFolderThread.absoluteImageList;
    this->imageName = loadFolderThread.imageName;
    progress.setValue(imageList.size());

    draw();
}


void MainWindow::addImageItem(QString imagename)
{
        QStandardItem *imageItem = new QStandardItem();
        imageItem->setIcon(QIcon(QPixmap(imagename)));
        imageListModel.appendRow(imageItem);
}

void MainWindow::on_actionFullscreen_triggered()
{
    if(this->isFullScreen()){
        showNormal();
        ui->menuBar->show();
        ui->statusBar->show();
        ui->mainToolBar->show();
    }else{
        showFullScreen();
        ui->menuBar->hide();
        ui->statusBar->hide();
        ui->mainToolBar->hide();
    }
}

void MainWindow::on_actionFit_to_screen_triggered()
{
    draw();
}

void MainWindow::scaleImage()
{
    if(ui->actionFit_to_screen->isChecked())
    {
        if(image.width() > image.height())
        {
            image = image.scaledToWidth(ui->scrollArea->width(), Qt::SmoothTransformation);
            if(image.height() > ui->scrollArea->height())
                image = image.scaledToHeight(ui->scrollArea->height(), Qt::SmoothTransformation);
        }else{
            image = image.scaledToHeight(ui->scrollArea->height(), Qt::SmoothTransformation);
            if(image.width() > ui->scrollArea->width())
                image = image.scaledToWidth(ui->scrollArea->width(), Qt::SmoothTransformation);
        }
    }

}


void MainWindow::draw()
{
    image = QPixmap(imageName);
    rotateImage();
    scaleImage();
    ui->imageLabel->setPixmap(image);
}

void MainWindow::rotateImage()
{
    image = image.transformed(QMatrix().rotate(angle));
}


void MainWindow::on_actionExit_triggered()
{
    close();
}


void MainWindow::on_actionHide_Listbox_triggered()
{
    if(ui->listView->isHidden()){
        ui->listView->show();
    }else{
        ui->listView->hide();
    }
    draw();
}

void MainWindow::on_imageLabel_redrawImage()
{
    draw();
}

void MainWindow::on_listView_newSelection(QModelIndex index)
{
        QStandardItem *item = imageListModel.itemFromIndex(index);
        imageName = imageList.at(item->row());
        draw();
}

void MainWindow::on_actionPrev_triggered()
{
    ui->listView->prev();
}

void MainWindow::on_actionNext_triggered()
{
    ui->listView->next();
}

void MainWindow::on_actionRotate_Clockwise_triggered()
{
    if(angle + 90 == 360)
        angle = 0;
    else
        angle += 90;
    draw();
}

void MainWindow::on_actionRotate_Counter_Clockwise_triggered()
{
    if(angle - 90 == 0)
        angle = 270;
    else
        angle -= 90;
    draw();
}

void MainWindow::pointerLoaded()
{
    ui->pointer->setModel(&(m_site->getPointers()));
}
