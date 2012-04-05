#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QStandardItemModel>
#include <QProgressDialog>
#include "loadfolderthread.h"
#include "pointermodel.h"
#include "connector.h"

namespace Ui
{
    class MainWindowClass;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString imageName;
    QString currentDirectory;
    QPixmap image;
    QStringList imageList;
    int angle;
    QStandardItemModel imageListModel;
    PointerModel pointerModel;

    QProgressDialog progress;
    LoadFolderThread loadFolderThread;
    Connector *m_site;

    void scaleImage();
    void draw();
    void populateList();
    void rotateImage();

private:
    Ui::MainWindowClass *ui;

private slots:
    void on_actionRotate_Counter_Clockwise_triggered();
    void on_actionRotate_Clockwise_triggered();
    void on_actionAdd_file_triggered();
    void on_actionNext_triggered();
    void on_actionPrev_triggered();
    void on_listView_newSelection(QModelIndex);
    void on_imageLabel_redrawImage();
    void on_actionHide_Listbox_triggered();
    void on_actionExit_triggered();
    void on_actionOpen_folder_triggered();
    void on_actionOpenFile_triggered();
    void on_actionFit_to_screen_triggered();
    void on_actionFullscreen_triggered();
    void endOfFolderLoad();
    void addImageItem(QString);
    void setupProgressDialog(int);
    void updateProgressDialog();
    void pointerLoaded();
};

#endif // MAINWINDOW_H
