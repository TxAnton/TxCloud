//
// Created by anton on 9/30/19.
//

#ifndef CODE_BTREE__H
#define CODE_BTREE__H

#include <iostream>
#include <cstdlib>

using namespace std;

template <class Elem>////Template class
class BinaryTree
{
private:
    struct binTree ///Core structure
    {
        binTree* left;
        binTree* right;
        Elem data;
    };
    binTree* root;
    ///constructor
public:
    BinaryTree()///Constructor
    {
        root =NULL;
    }

    BinaryTree(binTree* _root)///Constructor from ref
    {
        root =_root;
    }

    BinaryTree(Elem _el,BinaryTree l,BinaryTree r)///Constructor from values
    {
        root = new binTree;root->data=_el;root->left=l.root,root->right=r.root;///new binTree(_el,l.root,r.root);
    }
    BinaryTree(Elem _el){///Constructor from root only
        root = new binTree;root->data=_el;root->left=NULL,root->right=NULL;
    }

    ///prototypes
    bool isNull() const {return root == NULL;}///Empty tree
    Elem RootBT(){///Root value
        if(this->isNull()){ cerr << "Error: RootBT(null) \n"; exit(1); }
        else return root->data;
    }
    BinaryTree Left(){///Return left branch
        if(this->isNull()){ cerr << "Error: RootBT(null) \n"; exit(1); }
        else return BinaryTree(root->left);///*(new BinaryTree(root->left));
        }
    BinaryTree Right(){///Return right branch
        if(this->isNull()){ cerr << "Error: RootBT(null) \n"; exit(1); }
        else return BinaryTree(root->right);///*(new BinaryTree(root->right));
    }

    void destroy(){///Destroy this tree
        if(!isNull()){
            Left().destroy();
            Right().destroy();
            delete root;
        }
    }
};

#endif //CODE_BTREE__H
