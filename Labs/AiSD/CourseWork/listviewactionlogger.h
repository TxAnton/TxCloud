#ifndef LISTVIEWACTIONLOGGER_H
#define LISTVIEWACTIONLOGGER_H

#include <QObject>
#include <QListView>
#include <QStandardItemModel>
#include <QStandardItem>

#include <string>
#include <list>

#include "AVLTreeClass.h"

class ListViewActionLogger : public QListView
{
    Q_OBJECT
public:
    QStandardItemModel *model = new QStandardItemModel;//модель списка
    std::list<AVL::AVL<int> > treeList;//Список деревьев для каждого шага
signals:
    void reselect(int);
public slots:
    void logAction(std::string str, AVL::AVL<int> tree);
    void logText(std::string str);
    virtual void currentChanged(const QModelIndex&,const QModelIndex&);
    void clear();

};

#endif // LISTVIEWACTIONLOGGER_H
