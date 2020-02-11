#pragma once
#ifndef GRAPHGRAPHICVIEW_H
#define GRAPHGRAPHICVIEW_H
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QTimer>
#include <QTextBlockFormat>
#include <QTextCursor>
#include <QTextDocument>
#include "AVLTreeClass.h"


// Extend the class QGraphicsView
class GraphGraphicView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit GraphGraphicView(QGraphicsView *parent = nullptr);
    ~GraphGraphicView();

private:
    QGraphicsScene      *scene;//Graphics scene - canvas
    QGraphicsItemGroup  *group_1;//One group for elements containing
    QGraphicsItemGroup  *group_2;//Another one

    AVL::AVL<char> avltree;//Extra tree precaution purposes

    AVL::AVL<int> last_drawn_avl;//Last drawn tree saved for redrawing if needed
    int _width = 0;//Drawing field widtg
    int _height = 0;//Drawing field heitght
    float _nodeSize = 50;//Size of one tree node
    float _lvlInt = 0;//Interval between intervals

    QTimer              *timer;

signals:

public slots:
    void slotDrawAvl(AVL::AVL<int> _avl);
    void _slotDrawAvl(AVL::AVL<int> avl, int lvl, float xCoord);
    //void slotAlarmTimer();  /* slot timer overflow handler there will be repainting the widget*/
    void resizeEvent(QResizeEvent *event);
    void deleteItemsFromGroup(QGraphicsItemGroup *group_1);

};
//: QGraphicsView(parent)
#endif // GRAPHGRAPHICVIEW_H
