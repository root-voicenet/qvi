#include "qimagelabel.h"

QImageLabel::QImageLabel()
{
}

QImageLabel::QImageLabel(QWidget *parent) : QLabel(parent)
{
}

void QImageLabel::resizeEvent(QResizeEvent *event)
{
    emit(redrawImage());
    event->accept();
}

void QImageLabel::mouseReleaseEvent(QMouseEvent *pEvent)
{
    if(pEvent->button() == Qt::RightButton)
    {

      menu.exec(mapToGlobal(pEvent->pos()));
  }
}

void QImageLabel::addMenuItem(QAction *action)
{
    menu.addAction(action);
}
