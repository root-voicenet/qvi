#ifndef POINTERMODEL_H
#define POINTERMODEL_H

#include <QStandardItemModel>
// remove later
#include <QStringList>

class PointerModel : public QStandardItemModel
{
    Q_OBJECT

    friend class Connector;
public:
     explicit PointerModel(QObject *parent = 0);

    bool init(const QStringList &lines);
    QList<int> getSelectedPointers();
private:
    bool initFromJSON(const QStringList &lines);
    bool initFromRPC(QVariant *resp);

    QStandardItem *m_root;
};

#endif // POINTERMODEL_H
