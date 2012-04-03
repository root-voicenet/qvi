#ifndef LOADFOLDERTHREAD_H
#define LOADFOLDERTHREAD_H

#include <QThread>
#include <QDir>
#include <QStandardItemModel>


class LoadFolderThread : public QThread
{
Q_OBJECT
public:
    LoadFolderThread();
    void setValues(QString currentDirectory);
    virtual void run();
    QStringList absoluteImageList;
    QList<QStandardItem*> imageItemList;
    QList<QImage> qimageList;
    QString imageName;

private:
    bool stopped;
    QString currentDirectory;
    void populateList();

signals:
    void setupProgressDialog(int);
    void updateProgressDialog();
    void finished();
    void addImageItem(QString);
public slots:
    void stop();

};


#endif // LOADFOLDERTHREAD_H
