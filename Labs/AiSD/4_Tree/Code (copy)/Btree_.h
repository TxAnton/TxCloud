//
// Created by anton on 9/30/19.
//

#ifndef CODE_BTREE__H
#define CODE_BTREE__H

#include <iostream>
#include <cstdlib>

using namespace std;

template <class Elem>
class BinaryTree
{
private:
    struct binTree
    {
        binTree* left;
        binTree* right;
        Elem data;

        //binTree()
        //binTree(binTree* _left,binTree* _right,Elem _data){            left=_left;right=_right;data=_data;        }

    };
    binTree* root;
    //constructor
public:
    BinaryTree()
    {
        root =NULL;
    }

    BinaryTree(binTree* _root)
    {
        root =_root;
    }

    BinaryTree(Elem _el,BinaryTree l,BinaryTree r)
    {
        root = new binTree;root->data=_el;root->left=l.root,root->right=r.root;//new binTree(_el,l.root,r.root);
    }
    BinaryTree(Elem _el){
        root = new binTree(_el,NULL,NULL);
    }

    //prototypes
    bool isNull() const {return root == NULL;}
    Elem RootBT(){
        if(this->isNull()){ cerr << "Error: RootBT(null) \n"; exit(1); }
        else return root->data;
    }
    BinaryTree Left(){
        if(this->isNull()){ cerr << "Error: RootBT(null) \n"; exit(1); }
        else return *(new BinaryTree(root->left));
    }
    BinaryTree Right(){
        if(this->isNull()){ cerr << "Error: RootBT(null) \n"; exit(1); }
        else return *(new BinaryTree(root->right));
    }

    void destroy(){
        if(!isNull()){
            Left().destroy();
            Right().destroy();
            delete root;
        }
    }
/*
    static BinaryTree ConsBT(const Elem &x, BinaryTree lst, BinaryTree rst){
        return new BinaryTree(x,lst,rst);
    }
*/
    static BinaryTree Empty(){
        return new BinaryTree<Elem>();
    }


    void print_inorder();
    void inorder(binTree*);
    void insert(int);
    void search(int);

};
/*
void BinaryTree :: search(int d)
{
    bool found = false;
    if(isEmpty())
    {
        cout << "This tree is empty!" << endl;
        return;
    }
    binTree* curr;
    binTree* parent;
    curr = root;
    while (curr != NULL)
    {
        if(curr -> data ==d)
        {
            found  = true;
            break;
        }
        else
        {
            parent = curr;
            if(d> curr -> data) curr = curr -> right;
            else curr = curr -> left;
        }
    }
    if (!found)
    {
        cout <<"Data not found! " << endl;
    }
    else
        cout << "Element " << d << " is found " << endl;
}
//place small values in left and larger values in right side
//larger elements go right
void BinaryTree :: insert(int d)
{
    binTree* t = new binTree;
    binTree* parent;
    t-> data = d;
    t->left = NULL;
    t->right = NULL;
    //is this a new tree?
    if(isEmpty()) root = t;
    else
    {
        //Note : all insertions are as leaf noods
        binTree* curr;
        curr = root;
        //Find the Node's parent
        while(curr)
        {
            parent = curr;
            if(t-> data > curr ->data) curr = curr ->right;
            else curr = curr ->left;
        }
        if(t -> data < parent -> data)
            parent -> left = t;
        else
            parent -> right = t;
        cout << "Element " << d << " is inserted into tree " << endl;
    }
}
//to display inorder
void BinaryTree :: inorder(binTree* p)
{
    if( p != NULL)
    {
        if(p->left) inorder (p ->left);
        cout << " " << p -> data << "  ";
        if(p->right) inorder (p -> right);
    }
    else return;
}

*/

#endif //CODE_BTREE__H
