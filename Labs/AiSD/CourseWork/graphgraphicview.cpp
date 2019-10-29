#include "graphgraphicview.h"


GraphGraphicView::GraphGraphicView(QGraphicsView *parent) : QGraphicsView(parent) {

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Disable scroll horizontally
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Disable scroll vertically
    this->setAlignment(Qt::AlignCenter);                        // Make the contents of binding to the center
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Stretch the widget content

    this->setMinimumHeight(100);
    this->setMinimumWidth(100);

    scene = new QGraphicsScene();   // Initialize the scene to render
    this->setScene(scene);          // Set the scene in a widget

    group_1 = new QGraphicsItemGroup(); // Initialize the first group of elements
    group_2 = new QGraphicsItemGroup(); // Initialize the elements of the second group

    scene->addItem(group_1);            // Add the first group into the scene
    scene->addItem(group_2);            // Add the second group into the scene

    timer = new QTimer();               // Initialize Timer
    timer->setSingleShot(true);

    //_avl=AVL::AVL<int>();
    _width = this->width()*9/10;
    _height = this->height();

    timer->start(50);
}

GraphGraphicView::~GraphGraphicView()
{

}

void GraphGraphicView::slotDrawAvl(AVL::AVL<int> _avl)
{
    last_drawn_avl = _avl;//Save last drawn tree to redraw if needed
    this->deleteItemsFromGroup(group_1);//Clead groups
    this->deleteItemsFromGroup(group_2);//They will be refilled

    scene->setSceneRect(0,0,_width,_height);
    _lvlInt = (_height - 2*_nodeSize) / _avl.height();//Calculate interval between levels of tree
    if(!_avl.isEmpty())_slotDrawAvl(_avl,1,_width/2);//Is tree is not empty - draw it
    else{
        group_1->addToGroup(scene->addText("Empty tree!"));//Otherwise print empty tree tittle
    }
}

void GraphGraphicView::_slotDrawAvl(AVL::AVL<int> avl, int lvl, float xCoord)
{
    QPen penBlack(Qt::black);
    QPen penRed(Qt::red);
    int penWidth = penBlack.width();

    penRed.setWidth(2*penWidth);

    int x=xCoord;
    int y=_lvlInt*lvl-_lvlInt/2;

    if(avl.Root->highlight)// Draw root node
        group_1->addToGroup(scene->addEllipse(xCoord,y,_nodeSize,_nodeSize,penRed));
    else
        group_1->addToGroup(scene->addEllipse(xCoord,y,_nodeSize,_nodeSize,penBlack));

    //Do stuff with text. Here and hence!
    std::string strRoot = std::to_string( avl.root() );
    QFont font = QFont();
    font.setStyleHint(QFont::Monospace);

    font.setLetterSpacing(QFont::SpacingType::AbsoluteSpacing,0);

    font.setPixelSize(_nodeSize/strRoot.length());

    QGraphicsTextItem* text = scene->addText(QString::fromStdString( strRoot ),font);
    text->setTextWidth(_nodeSize);

    QTextBlockFormat format;//Text alignment
    format.setAlignment(Qt::AlignCenter);
    format.setIndent(0);
    format.setTextIndent(0);

    QTextCursor cursor = text->textCursor();
    cursor.select(QTextCursor::Document);
    cursor.mergeBlockFormat(format);
    cursor.clearSelection();
    text->setTextCursor(cursor);

    text->document()->setDocumentMargin(0);
    text->setTransformOriginPoint(xCoord+_nodeSize/2,(y)+_nodeSize/2);
    text->setPos(0,0);
    QRectF rect = text->boundingRect();
    text->setPos(xCoord+(_nodeSize-text->boundingRect().width())/2 ,y + (strRoot.length()==1? -10:strRoot.length()>2?15:0));//some magic going on here

    //Done messing with text

    group_1->addToGroup(text);//Adding text

    if(!avl.left().isEmpty()){//Draw left line
        if(avl.Root->highlightLeft)
            group_1->addToGroup(scene->addLine(xCoord,y+_nodeSize,xCoord-_width/(1<<(lvl+1))+_nodeSize/2,y+_lvlInt,penRed));
        else
            group_1->addToGroup(scene->addLine(xCoord,y+_nodeSize,xCoord-_width/(1<<(lvl+1))+_nodeSize/2,y+_lvlInt,penBlack));
        _slotDrawAvl(avl.left(),lvl+1,xCoord-_width/(1<<(lvl+1)));
    }
    else
    {
        if(avl.Root->highlightLeft)group_1->addToGroup(scene->addLine(xCoord,y+_nodeSize,xCoord-_width/(1<<(lvl+1))+_nodeSize/2,y+_lvlInt,penRed));
    }

    if(!avl.right().isEmpty()){//Draw right line
        if(avl.Root->highlightRight)
            group_1->addToGroup(scene->addLine(xCoord+_nodeSize,y+_nodeSize,xCoord+_width/(1<<(lvl+1))+_nodeSize/2,y+_lvlInt,penRed));
        else
            group_1->addToGroup(scene->addLine(xCoord+_nodeSize,y+_nodeSize,xCoord+_width/(1<<(lvl+1))+_nodeSize/2,y+_lvlInt,penBlack));

        _slotDrawAvl(avl.right(),lvl+1,xCoord+_width/(1<<(lvl+1)));
    }
    else
    {
        if(avl.Root->highlightRight)group_1->addToGroup(scene->addLine(xCoord+_nodeSize,y+_nodeSize,xCoord+_width/(1<<(lvl+1))+_nodeSize/2,y+_lvlInt,penRed));
    }

}// This method catches widget resize event

void GraphGraphicView::resizeEvent(QResizeEvent *event)
{
    timer->start(50);   // As soon as we start the timer event has occurred to render

    _width = this->width()*9/10;
    _height= this->height();
    slotDrawAvl(last_drawn_avl);

    QGraphicsView::resizeEvent(event);  //Run event the parent class
}


/* Method for removing all the elements from the group
 * */
void GraphGraphicView::deleteItemsFromGroup(QGraphicsItemGroup *group)
{
    /* Loop through all the elements of the scene,
     * and if they belong to the group, passed into the method, then delete them
     * */
    foreach( QGraphicsItem *item, scene->items(group->boundingRect())) {
       if(item->group() == group ) {
          delete item;
       }
    }
}
