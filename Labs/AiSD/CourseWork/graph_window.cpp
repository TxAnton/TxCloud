#include <QCloseEvent>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "graph_window.h"

GraphWindow::GraphWindow(QWidget *parent) : QMainWindow(parent)
{
    layout = new QHBoxLayout;
    central_widget = new QWidget;
    graphicsView = new GraphGraphicView();

    layout->addWidget(graphicsView);
    central_widget->setLayout(layout);
    setCentralWidget(central_widget);


}

GraphWindow::~GraphWindow()
{
    //TODO
}

void GraphWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "APP_NAME",
                                                                    tr("Are you sure?\n"),
                                                                    QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                    QMessageBox::Yes);
        if (resBtn != QMessageBox::Yes) {
            event->ignore();
        } else {
            event->accept();
        }
}
