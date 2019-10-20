#include "mygraphicsview.h"


MyGraphicsView::MyGraphicsView(QPixmap pixmap, QGraphicsView *parent) : QGraphicsView(parent) {
    start_point = new QPoint;
    end_point = new QPoint;
    pos = new QPoint;
    p1 = new QPoint;
    p2 = new QPoint;
    p3 = new QPoint;
    pc = 0;
    radius  = 0;

    pixmap_ = new QPixmap;
    *pixmap_ = pixmap;
    group = new QGraphicsItemGroup;
    mode = m_none;

    line_color = new QColor;
    fill_color = new QColor;

    isSquare = false;
    isTurn = false;

    this->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, pixmap_->width(), pixmap_->height());
    scene->addPixmap(pixmap);
    setScene(scene);
    scene->addItem(group);
}


MyGraphicsView::~MyGraphicsView() {
    delete group;
    delete pos;
    delete start_point;
    delete end_point;
    delete pixmap_;
    delete scene;
    delete line_color;
    delete fill_color;
}


int MyGraphicsView::updateImage(QPixmap pixmap) {
    scene->removeItem(group);
    scene->clear();
    *pixmap_ = pixmap;
    scene->setSceneRect(0, 0, pixmap.width(), pixmap.height());
    scene->addPixmap(pixmap);
    scene->addItem(group);
    return 0;
}


void MyGraphicsView::mousePressEvent(QMouseEvent *event) {
    *pos = MyGraphicsView::mapToScene(event->pos()).toPoint();
    qDebug()<< "press mode" << mode ;
    switch(mode){
    case m_triangle:
    {
        switch(pc)
        {

        case 0:*p1 = *pos;break;
        case 1:
        {
            *p2 = *pos;
            clearGroup(group);
            QPen pen(Qt::black);
            group->addToGroup(scene->addLine(p1->x(), p1->y(), p2->x(), p2->y(), pen));
            break;
        }
        case 2:
        {
            clearGroup(group);
            *p3 = *pos;
            pc = -1;
            qDebug()<< "emit sig_draw_triangle" << this ;
            emit sig_draw_triangle(p1,p2,p3,line_width, isFill, *line_color, *fill_color);
            break;
        }

        }
        pc++;
        break;
    }
    default:
    {
        int x = pos->x();
        int y = pos->y();
        if (pos->x() >= pixmap_->width())
            x = pixmap_->width() - 1;
        if (pos->x() < 0)
            x = 0;
        if (pos->y() >= pixmap_->height())
            y = pixmap_->height() - 1;
        if (pos->y() < 0)
            y = 0;

        start_point = new QPoint(x,y);break;
    }

    }
}


void MyGraphicsView::mouseMoveEvent(QMouseEvent* event) {
    *pos = MyGraphicsView::mapToScene(event->pos()).toPoint();

    switch(mode){

    case m_triangle:
    {
        break;
    }
    case m_cut:
    case m_invert:
    case m_rotate:
    case m_none:
    {
        int x = pos->x();
        int y = pos->y();
        if (pos->x() >= pixmap_->width())
            x = pixmap_->width() - 1;
        if (pos->x() < 0)
            x = 0;
        if (pos->y() >= pixmap_->height())
            y = pixmap_->height() - 1;
        if (pos->y() < 0)
            y = 0;

        clearGroup(group);
        QPen pen(Qt::black);
        group->addToGroup(scene->addLine(start_point->x(), start_point->y(), x, start_point->y(), pen));
        group->addToGroup(scene->addLine(start_point->x(), start_point->y(), start_point->x(), y, pen));
        group->addToGroup(scene->addLine(start_point->x(), y, x, y, pen));
        group->addToGroup(scene->addLine(x, start_point->y(), x, y, pen));
        break;
    }
        case m_line:
    {
        int x = pos->x();
        int y = pos->y();
        if (pos->x() >= pixmap_->width())
            x = pixmap_->width() - 1;
        if (pos->x() < 0)
            x = 0;
        if (pos->y() >= pixmap_->height())
            y = pixmap_->height() - 1;
        if (pos->y() < 0)
            y = 0;

        clearGroup(group);
        QPen pen(Qt::black);
        group->addToGroup(scene->addLine(start_point->x(), start_point->y(), x, y, pen));
        break;
    }
    }

}


void MyGraphicsView::mouseReleaseEvent(QMouseEvent *event) {
    *pos = MyGraphicsView::mapToScene(event->pos()).toPoint();

    switch(mode){
    case m_line:
    case m_invert:
    case m_cut:
    case m_rotate:
    case m_none:
    {
        *end_point = *pos;
        if (end_point->x() < 0)
            end_point->setX(0);
        if (end_point->x() >= pixmap_->width())
            end_point->setX(pixmap_->width() - 1);
        if (end_point->y() < 0)
            end_point->setY(0);
        if (end_point->y() >= pixmap_->height())
            end_point->setY(pixmap_->height() - 1);
        clearGroup(group);
    }
    }

    switch(mode){
    case m_cut:
    {
        emit sig_cut(start_point,end_point);
        break;
    }
    case m_invert:
    {
        int dim = _min( _abs(start_point->x() - end_point->x()), _abs(start_point->y() - end_point->y()) );
        QPoint* p = new QPoint( _min(start_point->x(), end_point->x()) + dim/2,  _min(start_point->y(), end_point->y()) + dim/2 );
        emit sig_draw_invert(p,dim/2);
        break;
    }
    case m_line:
    {
        emit sig_draw_line(start_point,end_point,line_width, *line_color);
        break;
    }
    case m_rotate:
        //qDebug()<<"sig_rotate";
        emit sig_rotate(start_point, end_point, angle);
        break;
    }

}


void MyGraphicsView::clearGroup(QGraphicsItemGroup* group_) {
    foreach(QGraphicsItem* item, scene->items(group_->boundingRect())) {
        if(item->group() == group_)
            delete item;
    }
}

void MyGraphicsView::sl_turn(Mode mode){
    qDebug() << "sl_turn" << mode ;
    //TO DO
}

void MyGraphicsView::sl_turn_tri(bool isFill, QColor* line_color, QColor* fill_color, int line_width){
    mode = m_triangle;
    pc = 0;
    this->isFill = isFill;
    this->line_color = line_color;
    this->fill_color = fill_color;
    this->line_width = line_width;

}


void MyGraphicsView::sl_turn_rot(int a){

    mode = m_rotate;
    qDebug() << "sl_turn_rot" << mode ;
    angle = a;
}

void MyGraphicsView::sl_turn_inv(){
    mode = m_invert;
}

void MyGraphicsView::sl_turn_cut(){
    mode = m_cut;
}

void MyGraphicsView::sl_turn_lin(int line_width,QColor* line_color){
    mode = m_line;
    pc = 0;
    this->line_color = line_color;
    this->line_width = line_width;
}
