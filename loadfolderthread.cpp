#include "loadfolderthread.h"

LoadFolderThread::LoadFolderThread()
{
    stopped = false;
}

void LoadFolderThread::setValues(QString currentDirectory)
{
    this->currentDirectory = currentDirectory;
}

void LoadFolderThread::run()
{
        stopped = false;
        absoluteImageList.clear();
        QDir dir(currentDirectory);
        QStringList newImageList = dir.entryList(QStringList() << "*.jpg" << "*.gif" << "*.png");
        QStringListIterator iter(newImageList);
        while (iter.hasNext() && !stopped)
        {
            absoluteImageList.push_back(QDir::toNativeSeparators(currentDirectory + "/" + iter.next()));
        }
        if(!stopped)
        {
                if(!absoluteImageList.isEmpty()){
                    populateList();
                }else{
                    imageName = "";
                }
        }
}

void LoadFolderThread::stop()
{
    stopped = true;
}

void LoadFolderThread::populateList()
{
    /*
    imageItemList.clear();
    QStringListIterator iter(absoluteImageList);
    while (iter.hasNext() && !stopped){
        QStandardItem *imageItem = new QStandardItem();
        imageItem->setIcon(QIcon(iter.next()));
        imageItemList.append(imageItem);
    }
    */
    emit setupProgressDialog(absoluteImageList.size());
    QStringListIterator iter(absoluteImageList);
    while (iter.hasNext() && !stopped)
    {
        emit updateProgressDialog();
        emit addImageItem(iter.next());
    }
    emit finished();
}
