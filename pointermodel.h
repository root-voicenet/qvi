#ifndef POINTERMODEL_H
#define POINTERMODEL_H

#include <QStandardItemModel>
// remove later
#include <QStringList>

class PointerModel : public QStandardItemModel
{
    Q_OBJECT
public:
     explicit PointerModel(QObject *parent = 0);

    bool init(const QStringList &lines);
private:
    bool initFromJSON(const QStringList &lines);
    QStandardItem *m_root;
};

#endif // POINTERMODEL_H
