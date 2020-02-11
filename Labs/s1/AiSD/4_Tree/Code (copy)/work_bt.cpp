// Пример работы с АТД "Бинарное дерево" (в процедурно-модульной парадигме)
#include <iostream>
#include <fstream>
#include <fstream>
#include <cstdlib>
//#include "Btree.h"
#include "Btree_.h"

#ifdef _WIN32
#include <windows.h>
#endif
using namespace std ;
//using namespace BinaryTree<char>_modul;

//typedef BinaryTree<char> *CharTree;

typedef unsigned int unInt;



BinaryTree<char> ConsBT(const char &x, BinaryTree<char> lst, BinaryTree<char> rst){
    return *(new BinaryTree<char>(x,lst,rst));
}
/*
CharTree _ConsBT(const char &x, BinaryTree<char> lst, BinaryTree<char> rst){
    return new BinaryTree<char>(x,lst,rst)0
}*/
/*
BinaryTree<char> ConsBT(const char &x){
    return *(new BinaryTree<char>(x));
}*/
BinaryTree<char> enterBT ();
void outBT(BinaryTree<char> b);
void displayBT (BinaryTree<char> b, int n);
unInt hBT (BinaryTree<char> b);
unInt mBT (BinaryTree<char> b);
unInt sizeBT (BinaryTree<char> b);
void printKLP (BinaryTree<char> b);
void printLKP (BinaryTree<char> b);
void printLPK (BinaryTree<char> b);
unInt knotsPerLvl(BinaryTree<char> b, int lvl);


ifstream infile ("KLP.txt");
int main () 
{
	BinaryTree<char> b;
#ifdef _WIN32
	//SetConsoleCP(1251);			// для вывода кирилицы
	//SetConsoleOutputCP(1251);	// для вывода кирилицы
#endif
	
	b = enterBT();
	cout << "Bin tree in Rlr representation" << endl;
	outBT(b);
	
	cout << "Bin tree flipped: " << endl;
	displayBT (b,1);
	cout << "Tree hight = " << hBT(b) << endl;
    cout << "Tree length = " << mBT(b) << endl;
	cout << "Tree's size (knot count)= " << sizeBT(b) << endl;
	
	cout << "Bit tree Rlr order: " << endl;
	printKLP(b);
	cout << endl;

	cout << "Bin tree in lRr order: " << endl;
	printLKP(b);
	cout << endl;

	cout << "Bin tree in lrR order: " << endl;
	printLPK(b);
	cout << endl;

    cout << "(knot count)= " << knotsPerLvl(b,4) << endl;

	b.destroy();
	outBT(b);
	cout << endl;
return (0);
}

//---------------------------------------
#define INS infile
/*
BinaryTree<char> _readExpr(){
    BinaryTree<char> b;
    char ch;
    char root;
    BinaryTree<char> l;
    BinaryTree<char> r;
    INS>>ch;
    while(ch ==' ')INS>>ch;
    if(ch == ')'){BinaryTree<char> b;return b;}

    root = ch;

    while(ch ==' ')INS>>ch;
    if(ch == ')'){BinaryTree<char> b(root);return b;}

    if(ch == '(') l = _readExpr();
    else if(ch=='/')l= BinaryTree
    l = ConsBT(ch);




}

BinaryTree<char> _enterBT(){

    char ch;
    INS>>ch;
    while(ch ==' ')INS>>ch;
    if(ch=='(')


}*/

    BinaryTree<char> enterBT ()
	{	char ch;
		BinaryTree<char> p, q;
		infile >> ch;
		if (ch=='/') return *(new BinaryTree<char>());
		else {p = enterBT(); q = enterBT(); return ConsBT(ch, p, q);}
	}
//---------------------------------------
	void outBT(BinaryTree<char> b) 
	{	
		if (!b.isNull()) {
			cout << b.RootBT();//b.RootBT()
			outBT(b.Left());
			outBT(b.Right());
		}
		else cout << '/';
	}

//---------------------------------------
	void displayBT (BinaryTree<char> b, int n)
	{	// n - уровень узла
		if (!b.isNull()) {
			cout << ' ' << b.RootBT();
			if(!b.Right().isNull()) {displayBT (b.Right(),n+1);}
			else cout << endl; // вниз
			if(!b.Left().isNull()) {
				for (int i=1;i<=n;i++) cout << "  "; // вправо
				displayBT (b.Left(),n+1);}
		}
		else {};
	}
//---------------------------------------
	unInt hBT (BinaryTree<char> b)
	{
		if (b.isNull()) return 0;
		else return max (hBT (b.Left()), hBT(b.Right())) + 1;
	}

    unInt mBT (BinaryTree<char> b)
    {
        if (b.isNull()) return 0;
        else return (hBT (b.Left())+hBT(b.Right())) + 1;
    }

unInt knotsPerLvl(BinaryTree<char> b, int lvl){
    if(lvl<1)return 0;
    lvl--;
    if(!b.isNull()){
        if(!lvl) return 1;
        else {
            int c1;
            c1 = knotsPerLvl(b.Left(), lvl);
            c1 += knotsPerLvl(b.Right(), lvl);
            return c1;
        }
    }
    else return 0;
}


//---------------------------------------
	unInt sizeBT (BinaryTree<char> b)
	{
		if (b.isNull()) return 0;
		else return sizeBT (b.Left())+ sizeBT(b.Right()) + 1;
	}
//---------------------------------------
	void printKLP (BinaryTree<char> b)
	{	if (!b.isNull()) {
			cout << b.RootBT();
			printKLP (b.Left());
			printKLP (b.Right());
		}
	}
//---------------------------------------
	void printLKP (BinaryTree<char> b)
	{	if (!b.isNull()) {
			printLKP (b.Left());
			cout << b.RootBT();
			printLKP (b.Right());
		}
	}
//---------------------------------------
	void printLPK (BinaryTree<char> b)
	{	if (!b.isNull()) {
			printLPK (b.Left());
			printLPK (b.Right());
			cout << b.RootBT();
		}
	}

