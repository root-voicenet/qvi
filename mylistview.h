#ifndef MYLISTVIEW_H
#define MYLISTVIEW_H

#include <QListView>

class MyListView : public QListView
{
    Q_OBJECT
public:
    MyListView();
    MyListView(QWidget * parent = 0);
    virtual void currentChanged ( const QModelIndex & current, const QModelIndex & previous );
    void next();
    void prev();
signals:
    void newSelection(QModelIndex index);
};

#endif // MYLISTVIEW_H
