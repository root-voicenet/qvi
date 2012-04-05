#include "pointermodel.h"
#include <QStandardItem>
#include <QDebug>

class TermInternal {
public:
    int tid;
    int depth;
    QList<int> parents;
    QString name;
    QList<TermInternal> children;
    QStandardItem* treeItem;
};

PointerModel::PointerModel(QObject *parent)
    : QStandardItemModel(parent)
{
    m_root = invisibleRootItem();
}

 bool PointerModel::init(const QStringList &lines)
 {
     return initFromJSON(lines);
 }



 bool PointerModel::initFromRPC(QVariant *resp)
 {
    QList<QVariant> elements(resp->toList());
    QList<TermInternal> items;
    QMap<int, TermInternal*> refs;

   for (int i = 0; i < elements.size(); ++i) {
       // parse element
       QMap<QString, QVariant> tags = elements[i].toMap();
       TermInternal term;

       term.name = tags.value("name").toString();
       term.depth = tags.value("depth").toInt();
       term.tid = tags.value("tid").toInt();

       // build a parents
       QList<QVariant> parents = tags.value("parents").toList();
       for(int j = 0; j < parents.size(); ++j) {
           term.parents.append(parents[j].toInt());
       }

       QStandardItem *item = new QStandardItem(term.name);
       item->setCheckable( true );
       item->setData(term.tid);
       term.treeItem = item;

       items.append(term);
       refs[term.tid] = &items.last();
   }

   // now we have flat list of pointers. build the tree from this list
   for(int i = 0; i < items.size(); i++) {
       QStandardItem *itemParent = m_root;
       if(!(items[i].parents.isEmpty()) && refs.contains(items[i].parents.first())) {
           int p = items[i].parents.first();
           itemParent = refs[items[i].parents[0]]->treeItem;
       }

       itemParent->appendRow(items[i].treeItem);
   }

 }

 bool PointerModel::initFromJSON(const QStringList &lines)
 {
    QList<QStandardItem*> parents;
    QList<int> indentations;
    parents << m_root;
    indentations << 0;

    int number = 0;

    while (number < lines.count()) {
     int position = 0;
     while (position < lines[number].length()) {
         if (lines[number].mid(position, 1) != " ")
             break;
         position++;
     }

     QString lineData = lines[number].mid(position).trimmed();

     if (!lineData.isEmpty()) {
         // Read the column data from the rest of the line.
         QStringList columnStrings = lineData.split("\t", QString::SkipEmptyParts);
         QList<QVariant> columnData;
         QString name = columnStrings[0];
         int tid  = columnStrings[1].toInt();

         if (position > indentations.last()) {
             // The last child of the current parent is now the new parent
             // unless the current parent has no children.

             if (parents.last()->rowCount() > 0) {
                 parents << parents.last()->child(parents.last()->rowCount()-1);
                 indentations << position;
             }
         } else {
             while (position < indentations.last() && parents.count() > 0) {
                 parents.pop_back();
                 indentations.pop_back();
             }
         }

         // Append a new item to the current parent's list of children.
         QStandardItem* item = new QStandardItem(name);
         item->setCheckable( true );

         parents.last()->appendRow(item);
     }

     number++;
    }

    return true;
 }
