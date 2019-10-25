#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QCloseEvent>
#include <QBoxLayout>
#include "graphgraphicview.h"

class GraphWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit GraphWindow(QWidget *parent = nullptr);
    ~GraphWindow();


private:
    QHBoxLayout *layout;
    QWidget *central_widget;
    GraphGraphicView* graphicsView;

signals:


private slots:
    void closeEvent(QCloseEvent *event);
};

#endif // GRAPHWINDOW_H
