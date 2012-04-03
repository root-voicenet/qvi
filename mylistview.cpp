#include "mylistview.h"

MyListView::MyListView()
{
}

MyListView::MyListView(QWidget *parent) : QListView(parent)
{
}

void MyListView::currentChanged( const QModelIndex & current, const QModelIndex & previous )
{
    emit(this->newSelection(current));
    this->scrollTo(current);
}

void MyListView::next()
{
    QModelIndex current = this->moveCursor(QAbstractItemView::MoveNext, Qt::NoModifier);
    this->setCurrentIndex(current);
}
void MyListView::prev()
{
    QModelIndex current = this->moveCursor(QAbstractItemView::MovePrevious, Qt::NoModifier);
    this->setCurrentIndex(current);
}
