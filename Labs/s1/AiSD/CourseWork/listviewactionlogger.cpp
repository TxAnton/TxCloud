#include "listviewactionlogger.h"


void ListViewActionLogger::logAction(std::string str, AVL::AVL<int> tree)
{
    QStandardItem *item;//элемент списка

    //добавление нового элемента
    //model = new QStandardItemModel;
    QString qstr =  QString().fromStdString(str);

    item = new QStandardItem(qstr);

    model->appendRow(item);

    treeList.push_back(tree);
    //соединение модели списка с конкретным списком
    this->setModel(model);
}

void ListViewActionLogger::logText(std::string str)
{
    QStandardItem *item;//элемент списка

    //добавление нового элемента
    //item = new QStandardItem(QString.fromStdString(str));
    //model->appendRow(item);

    //соединение модели списка с конкретным списком
    //this->setModel(model);

    return;
}

void ListViewActionLogger::currentChanged(const QModelIndex &cur, const QModelIndex &prv)
{
    emit reselect( cur.row() );
}

void ListViewActionLogger::clear()
{
    model->clear();
    treeList.clear();
    this->setModel(model);
}



