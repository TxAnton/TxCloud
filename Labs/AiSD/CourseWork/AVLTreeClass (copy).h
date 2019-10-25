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
private:



    struct node // структура для представления узлов дерева
    {
        Elem key;
        unsigned char height;
        node* left;
        node* right;
        node(Elem k) { key = k; left = right = 0; height = 1; }
    };

    node* Root;

    AVL(node* p)//Construct based on existing node(private)
    {
        Root = p;
    }

    int bfactor(node* p)//Balance factor -difference between branches
    {
        return _height(p->right)-_height(p->left);
    }

    void fixheight(node* p)//Recalculating height after other operations
    {
        unsigned char hl = _height(p->left);
        unsigned char hr = _height(p->right);
        p->height = (hl>hr?hl:hr)+1;
    }

    node* rotateright(node* p) // right rotation around p
    {
        if(AVL_DEBUG){printStr("Rotating right around '");printChar(p->key);printStr("'\n");}
        node* q = p->left;//Save left
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
            if( bfactor(p->right) < 0 ){
                p->right = rotateright(p->right);}

            return rotateleft(p);
        }
        if( bfactor(p)==-2 )//Disbalance to the left
        {
            if( bfactor(p->left) > 0  )
                p->left = rotateleft(p->left);
            return rotateright(p);
        }
        return p; // balance not required
    }

    node* findmin(node* p) // find minimal key node in tree p
    {
        return p->left?findmin(p->left):p;
    }

    node* removemin(node* p) // remove minimal key node from tree p
    {
        if( p->left==0 )
            return p->right;
        p->left = removemin(p->left);
        return balance(p);
    }

    node* _insert(node* p, Elem k, int lvl = 0) // insert key k in tree with root p
    {
        if( !p ) {// If tree is empty - found ins place
            if (AVL_DEBUG){
                for(int i=0;i<lvl;i++)printStr("\t");
                printStr("Insertion place!\n");
            }
            return new node(k);
        }
        if(AVL_DEBUG){
            for(int i=0;i<lvl;i++)printStr("\t");
            printStr("Current:");printChar(p->key);printChar('\n');
        }
        if( k<p->key ){ // if root is greater than key - go to left subtree
            if(AVL_DEBUG) {
                for (int i = 0; i < lvl; i++)printStr("\t");
                printStr("Going left\n");
            }
            p->left = _insert(p->left,k,lvl+1);
        }
        else {// if root is less than key - go to right subtree
            if(AVL_DEBUG) {
                for (int i = 0; i < lvl; i++)printStr("\t");
                printStr("Going right\n");
            }
            p->right = _insert(p->right, k,lvl+1);
        }
        /*
        if(DEBUG) {
            for (int i = 0; i < lvl; i++)printStr("\t");
            printStr("Rebalancing AVL\n");
        }
         */
        return balance(p);//Required before return
    }

    node* _remove(node* p, Elem k) // removing key k from tree p
    {
        if( !p ) return 0;//Empty - nothing to remove, key is absent
        if( k < p->key )// Looking for key to remove
            p->left = _remove(p->left,k); //less - to the left
        else if( k > p->key )
            p->right = _remove(p->right,k);//more - to the right
        else //  k == p->key found the key
        {
            node* q = p->left; // save left/right
            node* r = p->right;
            delete p; // delete key
            if( !r ) return q; // no right branch - all is fine
            node* min = findmin(r); // else - find least object in right subtree
            min->right = removemin(r); // swap it with deleted and remove from old place
            min->left = q;
            return balance(min);// required before return;
        }
        return balance(p);
    }

    unsigned char _height(node* p) // get tree hight
    {
        return p?p->height:0;
    }

    node* _copy(node* p){ // deep copy of tree
        if(!p)return 0;

        node* n = new node;
        n->key=p->key;
        n->left=_copy(p->left); //recursively  travel through
        n->right=_copy(p->right); // and make copies
        n->height=p->height;
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
        if(!p)return;
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

        Root=_insert(Root,key);
        if(AVL_DEBUG)printStr("Insertion completed\n");
    }

    void remove(Elem key) //Remove key k from this tree
    {
        Root=_remove(Root,key);
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
