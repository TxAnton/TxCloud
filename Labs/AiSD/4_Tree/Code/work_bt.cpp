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

#define DEFAULT_IFILE_NAME "in"
#define DEFAULT_OFILE_NAME "out"

using namespace std;

istream *inFile = NULL;
bool readFromFile = false;
ostream *outFile = NULL;
bool printToFile = false;
bool repeat = false;
bool awto = false;
int awtoLim = 0;
bool printLvl = false;
int lvl = 0;

void setIFile(istream* istr){
    //cin.rdbuf()
    //cin.rdbuf((*istr).rdbuf());
    inFile=istr;
}

void setOFile(ostream* ostr){
    //cout.rdbuf((*ostr).rdbuf());
    outFile=ostr;
}

int parseArgs(int argc, char** argv, string &iFileName, string &oFileName);	//Parses arguments. Returns 1 if program is to be closed

void printStr(string str);
void printInt(int str);
void printChar(char str);

typedef BinaryTree<char> *CharTree;

typedef unsigned int unInt;


BinaryTree<char> ConsBT(const char &x, BinaryTree<char> lst, BinaryTree<char> rst) {
    return BinaryTree<char>(x, lst, rst);//*(new BinaryTree<char>(x,lst,rst));
}


BinaryTree<char> ConsBT(const char &x) {
    return BinaryTree<char>(x);//*(new BinaryTree<char>(x));
}

BinaryTree<char> enterBT();

int _enterBT(BinaryTree<char> &b);

void outBT(BinaryTree<char> b);

void _outBT(BinaryTree<char> b);

void displayBT(BinaryTree<char> b, int n);

unInt hBT(BinaryTree<char> b);

unInt mBT(BinaryTree<char> b);

unInt sizeBT(BinaryTree<char> b);

void printKLP(BinaryTree<char> b);

void printLKP(BinaryTree<char> b);

void printLPK(BinaryTree<char> b);

unInt knotsPerLvl(BinaryTree<char> b, int lvl);

void help(){

    cout<<"-h\t\thelp\n";
    cout<<"-A\t\tAuto reading input line by line\n";
    cout<<"-l [N]\t\tLevel upon which to count nodes (0 by default)\n";
    cout<<"-r\t\tchose to repeat input after compliton. Incompatable with \"-i\"!\n";
    cout<<"-i [file]\t input from file (\""<<DEFAULT_IFILE_NAME<<"\" by default)\n";
    cout<<"-o [file]\t output to file (\""<<DEFAULT_OFILE_NAME<<"\" by default)\n";

}

ifstream infile("KLP.txt");

int main() {
    BinaryTree<char> b;
#ifdef _WIN32
    //SetConsoleCP(1251);			// для вывода кирилицы
    //SetConsoleOutputCP(1251);	// для вывода кирилицы
#endif

    if (_enterBT(b))return 1;
    printStr("Bin tree in Rlr representation\n");
    //printStr( "Bin tree in Rlr representation" << endl;
    outBT(b);


    printStr("Bin tree flipped: \n");
    //printStr( "Bin tree flipped: " << endl;
    displayBT(b, 1);
    printStr("Deepest level = ");
    printInt(hBT(b));
    printStr("\n");

    printStr("Total tree lenght = ");
    printInt(mBT(b));
    printStr("\n");

    //printStr( "Tree's size (knot count)= " << sizeBT(b) << endl;

    printStr("Bit tree Rlr order: \n");
    //printStr( "Bit tree Rlr order: " << endl;
    printKLP(b);
    printStr("\n");
    //printStr("\n");

    printStr("\"Bin tree in lRr order: \n");
    //printStr( "Bin tree in lRr order: " << endl;
    printLKP(b);
    printStr("\n");

    printStr("Bin tree in lrR order: \n");
    //printStr( "Bin tree in lrR order: " << endl;
    printLPK(b);
    printStr("\n");

    printStr("Knots per ");
    printInt(lvl);
    printStr(" lvl = ");
    printInt(knotsPerLvl(b, 4));

    //printStr( "(knot count)= " << knotsPerLvl(b, 4) << endl;
    _outBT(b);
    b.destroy();

    printStr("\n");
    return (0);
}

//---------------------------------------
#define INS ( readFromFile?(*inFile):cin )

int _readExpr(BinaryTree<char> &b) {
    // BinaryTree<char> b;
    char ch;
    char root;
    BinaryTree<char> l;
    BinaryTree<char> r;
    INS >> ch;
    while (ch == ' ')INS >> ch;
    if (ch == ')') { b = BinaryTree<char>(); }

    root = ch;

    INS >> ch;
    while (ch == ' ')INS >> ch;
    if (ch == ')') {
        b = BinaryTree<char>(root);
        return 0;
    }

    if (ch == '(') { if (_readExpr(l)) return 1; }
    else if (ch == '/')l = BinaryTree<char>();// *(new BinaryTree<char>());
    else l = ConsBT(ch);

    INS >> ch;
    while (ch == ' ')INS >> ch;
    if (ch == ')') {
        b = BinaryTree<char>(root, l, BinaryTree<char>());
        return 0;
    }

    if (ch == '(') { if (_readExpr(r)) return 1; }
    else if (ch == '/')r = BinaryTree<char>();// *(new BinaryTree<char>());
    else r = ConsBT(ch);

    INS >> ch;
    while (ch == ' ')INS >> ch;
    if (ch == ')') {
        b = BinaryTree<char>(root, l, r);
        return 0;
    } else {
        ///WROOOOOOOONG
        return 1;
    }

}

int _enterBT(BinaryTree<char> &b) {

    char ch;
    INS >> ch;
    while (ch == ' ')INS >> ch;
    if (ch == '(') { return _readExpr(b); }
    else {
        ///WROOOOOONG
        return 1;
        b = BinaryTree<char>();
    }


}

BinaryTree<char> enterBT() {
    char ch;
    BinaryTree<char> p, q;
    infile >> ch;
    if (ch == '/') return BinaryTree<char>();//*(new BinaryTree<char>());
    else {
        p = enterBT();
        q = enterBT();
        return ConsBT(ch, p, q);
    }
}

//---------------------------------------
void _outBT(BinaryTree<char> b) {
    if (!b.isNull()) {
        //if(b.Left().isNull() && b.Right().isNull()){cout<<b.RootBT()<<" ";return;}
        printStr( "( ");
        printChar( b.RootBT() );printStr( " ");//b.RootBT()
        _outBT(b.Left());
        _outBT(b.Right());
        printStr( ") ");
    } else printStr( "/ ");
}

void outBT(BinaryTree<char> b) {
    if (!b.isNull()) {
        printChar( b.RootBT());//b.RootBT()
        _outBT(b.Left());
        _outBT(b.Right());
    } else printStr( "/ ");
}

//---------------------------------------
void displayBT(BinaryTree<char> b, int n) {    // n - уровень узла
    if (!b.isNull()) {
        printStr( " ");printChar(b.RootBT());
        if (!b.Right().isNull()) { displayBT(b.Right(), n + 1); }
        else printStr("\n"); // вниз
        if (!b.Left().isNull()) {
            for (int i = 1; i <= n; i++) printStr( "  "); // вправо
            displayBT(b.Left(), n + 1);
        }
    } else {};
}

//---------------------------------------
unInt hBT(BinaryTree<char> b) {
    if (b.isNull()) return 0;
    else return max(hBT(b.Left()), hBT(b.Right())) + 1;
}

unInt mBT(BinaryTree<char> b) {
    if (b.isNull()) return 0;
    else return (hBT(b.Left()) + hBT(b.Right())) + 1;
}

unInt knotsPerLvl(BinaryTree<char> b, int lvl) {
    if (lvl < 1)return 0;
    lvl--;
    if (!b.isNull()) {
        if (!lvl) return 1;
        else {
            int c1;
            c1 = knotsPerLvl(b.Left(), lvl);
            c1 += knotsPerLvl(b.Right(), lvl);
            return c1;
        }
    } else return 0;
}


//---------------------------------------
unInt sizeBT(BinaryTree<char> b) {
    if (b.isNull()) return 0;
    else return sizeBT(b.Left()) + sizeBT(b.Right()) + 1;
}

//---------------------------------------
void printKLP(BinaryTree<char> b) {
    if (!b.isNull()) {
        printChar( b.RootBT());
        printKLP(b.Left());
        printKLP(b.Right());
    }
}

//---------------------------------------
void printLKP(BinaryTree<char> b) {
    if (!b.isNull()) {
        printLKP(b.Left());
        printChar( b.RootBT());
        printLKP(b.Right());
    }
}

//---------------------------------------
void printLPK(BinaryTree<char> b) {
    if (!b.isNull()) {
        printLPK(b.Left());
        printLPK(b.Right());
        printChar( b.RootBT());
    }
}
//---------------------------------------//---------------------------------------//---------------------------------------
void printStr(string str){
    cout<<str;
    if(printToFile&&outFile&&(*outFile))(*outFile)<<str;
}

void printInt(int str){
    cout<<str;
    if(printToFile&&outFile&&(*outFile))(*outFile)<<str;
}

void printChar(char str){
    cout<<str;
    if(printToFile&&outFile&&(*outFile))(*outFile)<<str;
}

int parseArgs(int argc, char** argv, string &iFileName, string &oFileName){
    //Run through all arguments looking for matches. Wrong keys are ignored. Wrong values leads to an undefined behaviour.


    int i=1;


    while(i<argc){
        if(!((string)argv[i]).compare("-h")){
            help();
            return 1;
        } else if(!((string)argv[i]).compare("-i")){
            readFromFile=true;
            if(i!=argc-1 && argv[i+1][0]!='-'){
                iFileName=(string)argv[i+1];
                i++;
            } else iFileName = DEFAULT_IFILE_NAME;
            i++;
        } else if(!((string)argv[i]).compare("-o")){
            printToFile=true;
            if(i!=argc-1 && argv[i+1][0]!='-'){
                oFileName=(string)argv[i+1];
                i++;
            } else oFileName = DEFAULT_OFILE_NAME;
            i++;
        } else if(!((string)argv[i]).compare("-r")){
            repeat=true;
            i++;
        }
        else if(!((string)argv[i]).compare("-A")){
            awto=true;
            if(i!=argc-1 && argv[i+1][0]!='-'){
                awtoLim=atoi(argv[i+1]);
                i++;
            } else awtoLim = 1;
            i++;
        } else if(!((string)argv[i]).compare("-l")){
            printLvl=true;
            if(i!=argc-1 && argv[i+1][0]!='-'){
                lvl=atoi(argv[i+1]);
                i++;
            } else lvl = 0;
            i++;
        }else i++;
    }
    /*
    if(awto && (readFromFile||repeat)){
        printStr("Warning! -A is incompatable with  -r and -i. These are ignored!\n");
        readFromFile=repeat=false;
    }*/
/*
    if((readFromFile||printToFile)&&repeat){
        repeat=false;
        printStr("Warning! -i and -o are incompatable with  -r. -r is ignored!\n");
    }
    */

    return 0;
}