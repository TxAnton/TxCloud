#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPoint>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItemGroup>
#include <QPixmap>
#include <QPen>
#include <QtDebug>

#define _abs(x) ( (x)<0?-(x):(x) )
#define _min(a,b) ( (a)>(b)?(b):(a) )
#define _max(a,b) ( (a)>(b)?(b):(a) )

enum Mode {m_none, m_triangle, m_cut, m_invert, m_line, m_new, m_rotate};

class DrawGraphicsView : public QGraphicsView {
    Q_OBJECT
public:
    explicit DrawGraphicsView(QPixmap pixmap, QGraphicsView *parent = nullptr);
    ~DrawGraphicsView();

private:
    QGraphicsScene *scene;
    QPoint* start_point;
    QPoint* end_point;
    QPoint* pos;
    QGraphicsItemGroup* group;
    QPixmap* pixmap_;
    QColor* line_color;
    QColor* fill_color;
    QPoint* p1;
    QPoint* p2;
    QPoint* p3;
    int pc;

    int radius;

    Mode mode;
    int line_width;
    bool isFill;
    bool isSquare;
    bool isTurn;
    int angle;

signals:

    void sig_draw_triangle(QPoint*,QPoint*,QPoint*,uint32_t, bool, QColor, QColor);
    void sig_draw_line(QPoint*,QPoint*,double, QColor);
    void sig_draw_invert(QPoint*, uint32_t);
    void sig_rotate(QPoint*, QPoint*, int);
    void sig_cut(QPoint*, QPoint*);

public slots:
    int updateImage(QPixmap pixmap);
    void sl_turn(Mode mode);
    void sl_turn_tri(bool isFill, QColor* line_color, QColor* fill_color, int line_width);
    void sl_turn_inv();
    void sl_turn_cut();
    void sl_turn_lin(int ,QColor*);
    void sl_turn_rot(int);

private slots:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void clearGroup(QGraphicsItemGroup* group_);
};

#endif // MYGRAPHICSVIEW_H
