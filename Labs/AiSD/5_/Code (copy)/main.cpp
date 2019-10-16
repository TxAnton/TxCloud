#include <iostream>
#include <fstream>
#include <cstdlib>

bool DEBUG = false;


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
bool debug = false;

void setIFile(istream* istr){
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

#include "AVLTreeClass.h"

typedef unsigned int unInt;



void _outAVL(AVL<char> b);//Formatter str tree output

void displayAVL(AVL<char> b, int n=1);//Fancy tree graph

void help(){

    cout<<"-h\t\thelp\n";
    cout<<"-A\t\tAuto reading input line by line\n";
    cout<<"-r\t\tchose to repeat input after compliton. Incompatable with \"-i\"!\n";
    cout<<"-i [file]\t input from file (\""<<DEFAULT_IFILE_NAME<<"\" by default)\n";
    cout<<"-o [file]\t output to file (\""<<DEFAULT_OFILE_NAME<<"\" by default)\n";
    cout<<"-d\t\toutput inter-processing data\n";

}

#define INS ( readFromFile?(*inFile):cin )

int main(int argc, char** argv) {
    ///Variables
    string iFileName;
    string oFileName;
    AVL<char> b;

    ///WIN setup
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif

    ///Parce argsuments
    if(parseArgs(argc,argv,iFileName,oFileName))exit(0);
    DEBUG=debug;
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

    ///Initial tree building

    char c=' ';
    vector<char> seq;
    if(!awto)printStr("Enter element sequence in a line:\n");
    c = INS.get();
    //INS>>c;
    while (c!='\n'){
        if(c==' '){c = INS.get();continue;}
        seq.push_back(c);
        c = INS.get();
    }
    printStr("Input:\n");
    for(auto it = seq.begin();it!=seq.end();it++)
    {
        printChar(*it);printChar(' ');
    }
    printChar('\n');
    printStr("Building AVL tree of entered sequence\n");
    DEBUG=false;
    b=AVL<char>(seq);
    DEBUG=debug;
    printStr("Built tree:\n");
    displayAVL(b);
    printChar('\n');


    do
    {///Main processing cycle

        ///Input

        if(!awto){
            printStr("Enter new element:\n");
            c=' ';
            while(c==' '||c=='\n')cin>>c;
        }else{
            c=' ';
            while((c==' ' ||c=='\n') && !INS.eof())INS>>c;
            if(INS.eof() && (c==' ' ||c=='\n')) {
                printStr("Input is over!\n");
                return 0;
            }
        }

        printStr("Entered element:\n");
        printChar(c);
        printChar('\n');
        if(!(b.find(c).empty())){
            printStr("Element already exists!\n");
        }else {
            printStr("Adding element\n");
            b.insert(c);
        }
        ///Representation
        printStr("Current AVL tree: \n");
        displayAVL(b, 1);
        printStr("\n");

        if(INS.eof()) {
            printStr("Input is over!\n");
            return 0;
        }
        ///Repeat condition
        if(!awto && repeat){
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

void _outAVL(AVL<char> b) {///Prints formatted string tree
    if (!b.empty()) {
        //if(b.left().empty() && b.right().empty()){cout<<b.root()<<" ";return;}
        printStr( "( ");
        printChar( b.root() );printStr( " ");//b.root()
        _outAVL(b.left());
        _outAVL(b.right());
        printStr( ") ");
    } else printStr( "/ ");
}


//---------------------------------------
void displayAVL(AVL<char> b, int n) {///Prints graphic tree
    if (!b.empty()) {
        printStr( " ");printChar(b.root());
        if (!b.right().empty()) { displayAVL(b.right(), n + 1); }
        else printStr("\n");
        if (!b.left().empty()) {
            for (int i = 1; i <= n; i++) printStr( "  ");
            displayAVL(b.left(), n + 1);
        }
    } else {}
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
        } else if(!((string)argv[i]).compare("-d")){
            debug=true;
            i++;
        } else if(!((string)argv[i]).compare("-A")){
            awto=true;
            if(i!=argc-1 && argv[i+1][0]!='-'){
                awtoLim=atoi(argv[i+1]);
                i++;
            } else awtoLim = 1;
            i++;
        } else i++;
    }

    return 0;
}

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