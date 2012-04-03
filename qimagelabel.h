#ifndef QIMAGELABEL_H
#define QIMAGELABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QMenu>

class QImageLabel : public QLabel
{
    Q_OBJECT
public:
    QImageLabel();
    QImageLabel(QWidget * parent = 0);
    void resizeEvent(QResizeEvent* anEvent);
    void mouseReleaseEvent(QMouseEvent* pEvent);
    void addMenuItem(QAction *action);

private:
    QMenu menu;

signals:
    void redrawImage();
};

#endif // QIMAGELABEL_H
