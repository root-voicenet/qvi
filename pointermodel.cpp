#include "pointermodel.h"
#include <QStandardItem>

PointerModel::PointerModel(QObject *parent)
    : QStandardItemModel(parent)
{
    m_root = invisibleRootItem();
}

 bool PointerModel::init(const QStringList &lines)
 {
     return initFromJSON(lines);
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
