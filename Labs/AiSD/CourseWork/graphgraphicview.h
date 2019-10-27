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
    QGraphicsScene      *scene;
    QGraphicsItemGroup  *group_1;
    QGraphicsItemGroup  *group_2;

    AVL::AVL<char> avltree;

    AVL::AVL<int> last_drawn_avl;
    int _width = 0;
    int _height = 0;
    float _nodeSize = 50;
    float _lvlInt = 0;

    /* Timer for delayed rendering.
     * The fact is that when you create a window and the widget
     * needs some time to parent layer turned to take
     * from him adequate width and height settings
     * */
    QTimer              *timer;

signals:

public slots:
    void slotDrawAvl(AVL::AVL<int> _avl);
    void _slotDrawAvl(AVL::AVL<int> avl, int lvl, float xCoord);
    void slotAlarmTimer();  /* slot timer overflow handler there will be repainting the widget*/
    void resizeEvent(QResizeEvent *event);
    void deleteItemsFromGroup(QGraphicsItemGroup *group_1);

};
//: QGraphicsView(parent)
#endif // GRAPHGRAPHICVIEW_H
