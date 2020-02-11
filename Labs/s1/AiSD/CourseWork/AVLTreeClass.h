//
// Created by anton on 10/15/19.
//
#pragma once
#ifndef CODE_AVLTREECLASS_H
#define CODE_AVLTREECLASS_H

#include <QtDebug>

#include <iostream>
#include <vector>
#include <string>

#ifndef AVL_DEBUG
#define AVL_DEBUG 0
#endif

static bool LOGGING=true;

class ListViewActionLogger;

//extern bool AVL_DEBUG;
static void printStr(std::string str)
{
    qDebug()<<"str";
}
static void printChar(char c)
{
    qDebug()<<"c";
}
namespace  AVL {

template <class Elem>////Template class
class AVL {

public:
    struct node // структура для представления узлов дерева
    {
        Elem key;

        unsigned char height;
        node* left;
        node* right;

        bool highlight=false;
        bool highlightLeft=false;
        bool highlightRight=false;

        node(Elem k) { key = k; left = right = 0; height = 1; }
    };

    ListViewActionLogger* logger;

    node* Root;
private:

    AVL(node* p)//Construct based on existing node(private)
    {
        Root = p;
    }

    void deselectall(node* p){//Disable all highlights
        if(!p)return;
        p->highlight=false;
        p->highlightLeft=false;
        p->highlightRight=false;
        deselectall(p->left);
        deselectall(p->right);
    }

    bool _isList(node *p){//Reterns true is node p is a list
        return (p && !p->left && !p->right);
    }

    int bfactor(node* p)//Balance factor -difference between branches heights
    {
        return _height(p->right)-_height(p->left);
    }

    void fixheight(node* p)//Recalculating height after other operations
    {
        unsigned char hl = _height(p->left);//Height of left branch
        unsigned char hr = _height(p->right);//Height of right branch
        p->height = (hl>hr?hl:hr)+1;//Hight eqs maximu of branches plus 1
    }

    node* rotateright(node* p) // right rotation around p
    {
        if(AVL_DEBUG){printStr("Rotating right around '");printChar(p->key);printStr("'\n");}
        node* q = p->left;//Save left subtree of p

        if(LOGGING){
            deselectall(Root);
            p->highlight=true;
            q->highlight=true;
            std::string logstr = "";logstr+="*\tBalancing: Rotating right around: ";logstr+=std::to_string(p->key);
            logstr+="\n\tLeft neighbour is element: ";logstr+=std::to_string(q->key);
            logger->logAction(logstr,AVL(p).copy());
            deselectall(Root);
        }

        p->left = q->right;//Transive common
        q->right = p; //Swap one under another
        fixheight(p); //Redo hight
        fixheight(q);
        return q;
    }

    node* rotateleft(node* q) // left rotation around q
    {
        if(AVL_DEBUG){printStr("Rotating left around '");printChar((q)->key);printStr("'\n");}
        node* p = q->right; //Save right

        if(LOGGING){
            deselectall(Root);
            p->highlight=true;
            q->highlight=true;
            std::string logstr = "";logstr+="*\tBalancing: Rotating left around: ";logstr+=std::to_string(q->key);
            logstr+="\n\tRight neighbour is element: ";logstr+=std::to_string(p->key);
            //logger->logAction(logstr,this->copy());
            logger->logAction(logstr,AVL(q).copy());
            deselectall(Root);
        }

        q->right = p->left; //Transive common
        p->left = q; //Swap one under another
        fixheight(q); //Redo hight
        fixheight(p);
        return p;
    }

    node* balance(node* p) // balancing node p
    {

        fixheight(p);
        if( bfactor(p)==2 )//Disbalance to the right
        {
            if( bfactor(p->right) < 0 ){//If right branch has disbalance to the left..
                p->right = rotateright(p->right);//Negate is, as after rotation it can cause further disbalance

                if(LOGGING)
                {
                    deselectall(Root);
                    if(p->right){
                        p->right->highlight=true;
                        if(p->right->left)
                            p->right->left->highlight=true;
                    }
                    std::string logstr = "";logstr+="*\t\tRotation right competed";
                    logger->logAction(logstr,this->copy());
                }
            }
            node* tmp = rotateleft(p);//Fix disbalance
            return tmp;
            //return rotateleft(p);
        }
        if( bfactor(p)==-2 )//Disbalance to the left
        {
            if( bfactor(p->left) > 0  ){//If left branch has disbalance to the right
                p->left = rotateleft(p->left);//Negate is, as after rotation it can cause further disbalance
                if(LOGGING)
                {
                    deselectall(Root);
                    if(p->left){
                        p->left->highlight=true;
                        if(p->left->right)
                            p->left->right->highlight=true;
                    }
                    std::string logstr = "";logstr+="*\t\t<<Rotation left competed>>";
                    logger->logAction(logstr,this->copy());
                }
            }
            node* tmp = rotateright(p);//Fix disbalance
/*
*/
            return tmp;
        }
        return p; // balance not required
    }

    node* findmin(node* p) // find minimal key node in tree p
    {

        if(p->left){
            if(LOGGING)
            {
                p->highlightLeft=true;
                std::string logstr = "";logstr+="*\t\tCurrent min: ";logstr+=std::to_string(p->key);
                logstr+="\n\t\tGoing Left";
                logger->logAction(logstr,this->copy());
            }
            return findmin(p->left);
        }
        else{
            if(LOGGING)
            {
                p->highlight=true;
                std::string logstr = "";logstr+="*\t\tFound min: ";logstr+=std::to_string(p->key);
                logger->logAction(logstr,this->copy());
            }

            return p;
        }

        return p->left?findmin(p->left):p;
    }

    node* removemin(node* p) // remove minimal key node from tree p, one that pointed on it now pointing on its right element
    {

        if( p->left==0 )
            return p->right;
        p->left = removemin(p->left);
        LOGGING=false;
        return balance(p);
    }

    node* _insert(node* p, Elem k, int lvl = 0) // insert key k in tree with root p
    {
        if( !p ) {// If tree is empty - found its place
            if (AVL_DEBUG){
                for(int i=0;i<lvl;i++)printStr("\t");
                printStr("Insertion place!\n");
            }

            node *n = new node(k);//New node...
            n->highlight=true;
            return n;//Stands instead of an empty sub-tree
        }
        if(AVL_DEBUG){
            for(int i=0;i<lvl;i++)printStr("\t");
            printStr("Current:");printChar(p->key);printChar('\n');
        }
        if(k==p->key){
            if (AVL_DEBUG){
                for(int i=0;i<lvl;i++)printStr("\t");
                printStr("Element already exists. Nothing is added!\n");
            }

            if(LOGGING)
            {

                std::string logstr = "";logstr+="*\tElement: ";logstr+=std::to_string(k);logstr+=" already exists. Nothing is added!";
                p->highlight=true;
                logger->logAction(logstr,this->copy());
                deselectall(Root);
                p->highlight=true;
            }
            return p;
        }
        else if( k<p->key ){ // if root is greater than key - go to left subtree
            if(AVL_DEBUG) {
                for (int i = 0; i < lvl; i++)printStr("\t");
                printStr("Going left\n");
            }
            if(LOGGING)
            {
                p->highlightRight=false;
                p->highlightLeft=true;
                std::string logstr = "";logstr+="*\tInserting element: ";logstr+=std::to_string(k);
                logstr+="\n\tCurent root: ";logstr+=std::to_string(p->key);
                logstr+="\n\tElement is smaller thar root => ";
                logstr+="Going Left";
                logger->logAction(logstr,this->copy());
            }

            p->left = _insert(p->left,k,lvl+1);

            if(LOGGING && _isList(p->left)){
                fixheight(Root);

                std::string logstr = "";logstr+="*\tInserted element: ";logstr+=std::to_string(k);
                logger->logAction(logstr,this->copy());
                deselectall(Root);
            }
        }
        else {// if root is less than key - go to right subtree
            if(AVL_DEBUG) {
                for (int i = 0; i < lvl; i++)printStr("\t");
                printStr("Going right\n");
            }
            if(LOGGING)
            {
                p->highlightLeft=false;
                p->highlightRight=true;
                std::string logstr = "";logstr+="*\tInserting element: ";logstr+=std::to_string(k);
                logstr+="\n\tCurent root: ";logstr+=std::to_string(p->key);
                logstr+="\n\tElement is bigger thar root => ";
                logstr+="Going Right";
                //if(!p->right) Root->height+=1;
                logger->logAction(logstr,this->copy());
                //if(!p->right)Root->height-=1;
            }

            p->right = _insert(p->right, k,lvl+1);

            if(LOGGING && _isList(p->right)){
                fixheight(Root);
                fixheight(Root);
                std::string logstr = "";logstr+="*\tInserted element: ";logstr+=std::to_string(k);
                logger->logAction(logstr,this->copy());
                deselectall(Root);
            }
        }
        return balance(p);//Required before return
    }

    node* _remove(node* p, Elem k) // removing key k from tree p
    {
        if( !p ) {//Not found

            if(LOGGING)
            {
                std::string logstr = "";logstr+="*\tElement: ";logstr+=std::to_string(k);logstr+=" not found. Nothing to remove!";
                logger->logAction(logstr,this->copy());
            }
            return 0;//Empty - nothing to remove, key is absent
        }
        //  Looking for key to remove.
        if( k < p->key ){//  Key is less than root
            if(LOGGING)
            {
                p->highlightRight=false;
                p->highlightLeft=true;
                std::string logstr = "";logstr+="*\tRemoving element: ";logstr+=std::to_string(k);
                logstr+="\n\tCurent root: ";logstr+=std::to_string(p->key);
                logstr+="\n\tElement is smaller thar root => ";
                logstr+="Going Left";
                logger->logAction(logstr,this->copy());
            }

            p->left = _remove(p->left,k); //less - to the left
        }
        else if( k > p->key ){//Key is more than root
            if(LOGGING)
            {
                p->highlightLeft=false;
                p->highlightRight=true;
                std::string logstr = "";logstr+="*\tRemoving element: ";logstr+=std::to_string(k);
                logstr+="\n\tCurent root: ";logstr+=std::to_string(p->key);
                logstr+="\n\tElement is bigger thar root => ";
                logstr+="Going Right";
                logger->logAction(logstr,this->copy());
            }

            p->right = _remove(p->right,k);//more - going to the right
        }
        else //  k == p->key ; found the key
        {
            if(LOGGING){
                p->highlight=true;
                std::string logstr = "";logstr+="*\tFound element to remove: ";logstr+=std::to_string(k);
                logger->logAction(logstr,this->copy());
            }

            node* q = p->left; // save left/right
            node* r = p->right;
            //delete p; // delete key
            if( !r ){
                delete p; // delete key
                return q; // no right branch - all is fine
            }

            if(LOGGING){
                deselectall(Root);
                std::string logstr = "";logstr+="*\tLooking for min in right subtree of ";logstr+=std::to_string(k);logstr+=" which is: ";logstr+=std::to_string(r->key);
                r->highlight=true;
                logger->logAction(logstr,this->copy());
                deselectall(Root);
            }
            node* min = findmin(r); // else - find least object in right subtree

            if(LOGGING)
            {
                deselectall(Root);
                p->highlight=true;
                min->highlight=true;
                std::string logstr = "";logstr+="*\tMin in right subtree of ";logstr+=std::to_string(k);logstr+=" found: ";logstr+=std::to_string(min->key);
                logstr+="\n\tSet min instead of element to delete and remove from old place. (Old place gets balanced)";
                logger->logAction(logstr,this->copy());
            }

            min->right = removemin(r); // swap it with deleted and remove from old place. Old place gets balanced
            LOGGING=true;
            min->left = q;
            delete p; // delete key
            return balance(min);// required before return;
        }
        return balance(p);
    }

    unsigned char _height(node* p) // get tree hight
    {
        if(!p)return 0;
        fixheight(p);
        return p?p->height:0;
    }

    node* _copy(node* p){ // deep copy of tree
        if(!p)return 0;

        node* n = new node(p->key);
        //n->key=p->key;
        n->left=_copy(p->left); //recursively  travel through
        n->right=_copy(p->right); // and make copies
        n->height=p->height;
        n->highlight=p->highlight;
        n->highlightLeft=p->highlightLeft;
        n->highlightRight=p->highlightRight;
        return n;
    }

    node* _find(node* p, Elem k, int lvl = 0) // search for key k in tree p
    {

        if( !p ) {// Empty - not found
            if(AVL_DEBUG)printStr("Not found!\n");
            return 0;
        }
        if(AVL_DEBUG){
            for(int i=0;i<lvl;i++)printStr("\t");
            printStr("Current:");printChar(p->key);printChar('\n');
        }
        if(k == p->key){ // Equal - found
            if(AVL_DEBUG){
                //for(int i=0;i<lvl;i++)printStr("\t");
                printStr("Found!\n");
            }
            return p;
        }
        if( k < p->key ) { // less - go left
            if(AVL_DEBUG){
                for(int i=0;i<lvl;i++)printStr("\t");
                printStr("Looking left\n");
            }
            return _find(p->left, k,lvl+1);
        }
        else if( k > p->key ){ // more - go roght
            if(AVL_DEBUG){
                for(int i=0;i<lvl;i++)printStr("\t");
                printStr("Looking right\n");
            }
            return _find(p->right,k,lvl+1);
        }
    }

    void _destroy(node* p){ // deep destroy of tree p
        if(!p)return;static bool LOGGING=true;
        _destroy(p->left);
        _destroy(p->right);
        delete p;
    }

public:

    AVL()//Default constructor
    {
        Root=0;
    }

    AVL(std::vector<Elem> keys)//Cunstruct and initialize with keys
    {
        Root=0;
        for(auto it = keys.begin();it!=keys.end();it++){
            insert(*it);
        }
    }


    bool isEmpty(){ //Whether tree is empty
        return Root==0;
    }

    bool isList(){
        return (Root && !Root->left && !Root->right);
    }

    void insert(Elem key) //Insert key k in this tree
    {
        if(AVL_DEBUG){
            printStr("Inserting element '");
            printChar((char)key);
            if(isEmpty()){
                printStr("' in empty subtree\n");
            }else {
                printStr("' in subtree with root '");
                printChar(root());
                printStr("'\n");
            }
        }
        if(LOGGING)
        {
            std::string logstr = "";logstr+="# Inserting element: ";logstr+=std::to_string(key);
            logger->logAction(logstr,this->copy());
        }
        Root=_insert(Root,key);
        if(LOGGING)
        {
            std::string logstr = "";logstr+="# Insertion completed of element: ";logstr+=std::to_string(key);
            deselectall(Root);
            logger->logAction(logstr,this->copy());
        }



        if(AVL_DEBUG)printStr("Insertion completed\n");
    }

    void remove(Elem key) //Remove key k from this tree
    {
        if(LOGGING)
        {
            std::string logstr = "";logstr+="# Removing element: ";logstr+=std::to_string(key);
            logger->logAction(logstr,this->copy());
        }

        Root=_remove(Root,key);

        if(LOGGING)
        {
            std::string logstr = "";logstr+="# Removing completed of element: ";logstr+=std::to_string(key);
            deselectall(Root);
            logger->logAction(logstr,this->copy());
        }

    }

    unsigned char height() //Height(depth) of this tree
    {
        return Root?Root->height:0;
    }

    AVL find(Elem key) //Search for key in this tree. Return subtree with root 'key'
    {
        if(AVL_DEBUG){
            printStr("Searching for '");
            printChar((char)key);
            if(isEmpty()){
                printStr("' in empty subtree\n");
            }else {
                printStr("' in subtree with root '");
                printChar(root());
                printStr("'\n");
            }
        }
        node* n =_find(Root,key);
        if(AVL_DEBUG)printStr("Search completed\n");
        return AVL(n);
    }

    AVL copy(){// deep copy of tree
        return AVL(_copy(Root));
    }

    AVL left(){// get left subtree
        if(!Root){ std::cerr << "Error: left(null) \n"; exit(1); }
        return AVL(Root->left);
    }

    AVL right(){// get right subtree
        if(!Root){ std::cerr << "Error: right(null) \n"; exit(1); }
        return AVL(Root->right);
    }

    Elem root(){// get root value
        if(!Root){ std::cerr << "Error: root(null) \n"; exit(1); }
        return Root->key;
    }

    void destroy(){//suicide
        _destroy(Root);
        Root=0;
    }

};//class AVL

}//namespace AVL

#endif //CODE_AVLTREECLASS_H
