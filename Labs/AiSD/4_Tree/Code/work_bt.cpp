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

int _max(int a, int b){return a>b?a:b;}

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



int _enterBT(BinaryTree<char> &b);//Input

void _outBT(BinaryTree<char> b);//Formatter str tree output

void displayBT(BinaryTree<char> b, int n);//Fancy tree graph

unInt hBT(BinaryTree<char> b,int reclvl=0);//Max depth(hight)

unInt mBT(BinaryTree<char> b,int reclvl=0);//Summ of all knot-to-root pathes

unInt sizeBT(BinaryTree<char> b);//Size thes BinTree

void printKLP(BinaryTree<char> b);//Print tree Rlr

void printLKP(BinaryTree<char> b);//Print tree lRr

void printLPK(BinaryTree<char> b);//Print tree lrR

unInt knotsPerLvl(BinaryTree<char> b, int lvl);//Calculates knots per given level

void printLeaves(BinaryTree<char> b,int reclvl=0);//Prints leaves in lr order

void help(){

    cout<<"-h\t\thelp\n";
    cout<<"-A\t\tAuto reading input line by line\n";
    cout<<"-l [N]\t\tLevel upon which to count nodes (0 by default)\n";
    cout<<"-r\t\tchose to repeat input after compliton. Incompatable with \"-i\"!\n";
    cout<<"-i [file]\t input from file (\""<<DEFAULT_IFILE_NAME<<"\" by default)\n";
    cout<<"-o [file]\t output to file (\""<<DEFAULT_OFILE_NAME<<"\" by default)\n";

}
#define INS ( readFromFile?(*inFile):cin )
//ifstream infile("KLP.txt");

int main(int argc, char** argv) {

    ///Variables
    string iFileName;
    string oFileName;
    BinaryTree<char> b;

    ///WIN setup
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif

    ///Parce argsuments
    if(parseArgs(argc,argv,iFileName,oFileName))exit(0);

    ofstream oFile;
    ifstream iFile;

    ///File management
    if (printToFile){
        oFile.open(oFileName,ios::out);
        if(!oFile){
            printStr("Cannot open file: "+oFileName+"\n");
            exit(1);
        }
        setOFile(&oFile);
    }
    if (readFromFile) {
        iFile.open(iFileName);
        if (!iFile) {
            printStr("Cannot open file: " + iFileName + "\n");
            exit(1);
        }
        setIFile(&iFile);
    }

    do
    {///Main inpit-process-output-out cycle

        ///Input

        if(!awto)printStr("Enter tree sequense:\n");

        if(_enterBT(b)){
            if(INS.eof()){printStr("Input is over!\n");return 0;}
            if(INS.fail()){printStr("Input stuck!\n");return 0;}
            printStr("Wrong input data!\n");
            continue;
        }
        printStr("Input: ");
        _outBT(b);
        printStr("\n");

        ///Processing

        ///Representation
        printStr("Bin tree flipped: \n");
        displayBT(b, 1);

        ///REal processing

        printStr("Deepest level(max depth of l/r branches+1) = \n");
        printInt(hBT(b));
        printStr("\n");

        printStr("Total tree lenght(sum of l/r brances + self's) = \n");
        printInt(mBT(b));
        printStr("\n");

        //printStr( "Tree's size (knot count)= " << sizeBT(b) << endl;
/*
        printStr("Bit tree Rlr order: \n");
        //printStr( "Bit tree Rlr order: " << endl;
        printKLP(b);
        printStr("\n");
        //printStr("\n");

        printStr("Bin tree in lRr order: \n");
        //printStr( "Bin tree in lRr order: " << endl;
        printLKP(b);
        printStr("\n");

        printStr("Bin tree in lrR order: \n");
        //printStr( "Bin tree in lrR order: " << endl;
        printLPK(b);
        printStr("\n");
*/
        printStr("Leaves in lr order: \n");
        printLeaves(b);
        printStr("\n");
        ///Dat is optional
        if(printLvl){
            printStr("Knots per ");
            printInt(lvl);
            printStr(" lvl = ");
            printInt(knotsPerLvl(b, lvl));
            printStr("\n");
        }

        b.destroy();

        printStr("\n");

        ///Repeat condition
        if(repeat){
            printStr("\nRepeat? [1-Yes|0-No]\n");
            cin.clear();
            int t;
            cin >> t;
            repeat = t;
            if (repeat)printStr("\n");
            else printStr("Good bye!\n");
        }

    }while(repeat || awto);
    return (0);
}

//---------------------------------------

///Read tree expression. Called from _enterBT
int _readExpr(BinaryTree<char> &b) {
    // BinaryTree<char> b;
    char ch;
    char root;
    BinaryTree<char> l;
    BinaryTree<char> r;

    ///Read before first
    INS >> ch;
    while (ch == ' ')INS >> ch;
    if (ch == ')') { b = BinaryTree<char>();return 0; }
    ///Read root
    root = ch;

    INS >> ch;
    while (ch == ' ')INS >> ch;
    if (ch == ')') {
        b = BinaryTree<char>(root);
        return 0;
    }
    ///Read left
    if (ch == '(') { if (_readExpr(l)) return 1; }
    else if (ch == '/')l = BinaryTree<char>();// *(new BinaryTree<char>());
    else l = ConsBT(ch);

    INS >> ch;
    while (ch == ' ')INS >> ch;
    if (ch == ')') {
        b = BinaryTree<char>(root, l, BinaryTree<char>());
        return 0;
    }
    ///Read right
    if (ch == '(') { if (_readExpr(r)) return 1; }
    else if (ch == '/')r = BinaryTree<char>();// *(new BinaryTree<char>());
    else r = ConsBT(ch);
    ///Read to the end
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

///User function for tree reading
int _enterBT(BinaryTree<char> &b) {//Input

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
/*
BinaryTree<char> enterBT() {
    char ch;
    BinaryTree<char> p, q;
    INS >> ch;
    if (ch == '/') return BinaryTree<char>();
    else {
        p = enterBT();
        q = enterBT();
        return ConsBT(ch, p, q);
    }
}*/

//---------------------------------------

void _outBT(BinaryTree<char> b) {///Prints formatted string tree
    if (!b.isNull()) {
        //if(b.Left().isNull() && b.Right().isNull()){cout<<b.RootBT()<<" ";return;}
        printStr( "( ");
        printChar( b.RootBT() );printStr( " ");//b.RootBT()
        _outBT(b.Left());
        _outBT(b.Right());
        printStr( ") ");
    } else printStr( "/ ");
}


//---------------------------------------
void displayBT(BinaryTree<char> b, int n) {///Prints graphic tree
    if (!b.isNull()) {
        printStr( " ");printChar(b.RootBT());
        if (!b.Right().isNull()) { displayBT(b.Right(), n + 1); }
        else printStr("\n");
        if (!b.Left().isNull()) {
            for (int i = 1; i <= n; i++) printStr( "  ");
            displayBT(b.Left(), n + 1);
        }
    } else {};
}

//---------------------------------------
///Main task stuff
unInt hBT(BinaryTree<char> b,int reclvl) {///Find hight
    if (b.isNull()) return 0;
    else {
        printStr("\n");
        for(int i=0;i<reclvl;i++)printStr("\t");
        printStr("Check:");printChar(b.RootBT());

        ///Takes highest of two branches
        int c =max(hBT(b.Left(),reclvl+1), hBT(b.Right(),reclvl+1)) + 1;
        ///Echoing
        for (int i = 0; i < reclvl; ++i) {printStr("\t");}
        printStr("\n");
        for(int i=0;i<reclvl;i++)printStr("\t");
        printStr("Depth:");
        printInt(c);
        printStr("\n");
        ///This would be it
        return c;
    }
}

unInt mBT(BinaryTree<char> b, int reclvl) {///Summ of all knot-to-root pathes
    if (b.isNull()) return 0;
    else {
        printStr("\n");
        for(int i=0;i<reclvl;i++)printStr("\t");
        printStr("Check:");printChar(b.RootBT());


        ///Takes summ of branches's deepnesses + self's
        int l=mBT(b.Left(),reclvl+1);///Summ by left branch
        int r=mBT(b.Right(),reclvl+1);///Summ by right branch
        int c =(l + r + reclvl);///Summ  of summs + self
        ///Echoing
        for (int i = 0; i < reclvl; ++i) {printStr("\t");}
        printStr("\n");
        for(int i=0;i<reclvl;i++)printStr("\t");
        printStr("Dist to root:");
        printInt(c);
        printStr("\n");
        ///This would'ge'n' be it as well
        return c;
    }
}

unInt knotsPerLvl(BinaryTree<char> b, int lvl) {//Calculates knots per given level
    ///Precautions
    if (lvl < 1)return 0;
    ///Decrease for counting
    lvl--;
    if (!b.isNull()) {
        if (!lvl) return 1;/// If zero - we found one knot
        else {
            int c1;
            ///Take all needed knots
            c1 = knotsPerLvl(b.Left(), lvl);
            ///From both branches
            c1 += knotsPerLvl(b.Right(), lvl);
            return c1;
        }
    } else return 0;
}

void printLeaves(BinaryTree<char> b,int reclvl) {///Prints all leaves lr
    static string s = "";
    if (b.isNull()) return;
    else {
        printStr("\n");
        for(int i=0;i<reclvl;i++)printStr("\t");
        printStr("Check:");printChar(b.RootBT());
        if(b.Left().isNull()&&b.Right().isNull()) {
            if(b.RootBT()!='/'){
                printStr(":Found leave!");
                s+=b.RootBT();s+=+" ";
                //printChar(b.RootBT());printStr(" ");
            }// We print it.
            else printStr("\n");
        }
        printLeaves(b.Left(),reclvl+1); //Go looking for others recursively
        printLeaves(b.Right(),reclvl+1);
        if(reclvl==0)printStr("\n"+s);
        return;
    }
}
//---------------------------------------
///Utility stuff
unInt sizeBT(BinaryTree<char> b) {
    if (b.isNull()) return 0;
    else return sizeBT(b.Left()) + sizeBT(b.Right()) + 1;
}

//---------------------------------------
void printKLP(BinaryTree<char> b) {//Print tree Rlr
    if (!b.isNull()) {
        printChar( b.RootBT());
        printKLP(b.Left());
        printKLP(b.Right());
    }
}

//---------------------------------------
void printLKP(BinaryTree<char> b) {//Print tree lRr
    if (!b.isNull()) {
        printLKP(b.Left());
        printChar( b.RootBT());
        printLKP(b.Right());
    }
}

//---------------------------------------
void printLPK(BinaryTree<char> b) {//Print tree lrR
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