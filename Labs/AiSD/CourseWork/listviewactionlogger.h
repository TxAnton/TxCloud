#ifndef LISTVIEWACTIONLOGGER_H
#define LISTVIEWACTIONLOGGER_H

#include <QObject>
#include <QListView>
#include <QStandardItemModel>
#include <QStandardItem>

#include <string>

class ListViewActionLogger : public QListView
{
    Q_OBJECT
public:
    QStandardItemModel *model;//модель списка
signals:

public slots:
    void logText(std::string str);
};

#endif // LISTVIEWACTIONLOGGER_H
