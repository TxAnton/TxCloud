/*  использование модуля с АТД "Иерархический Список" .
Интерфейс модуля в заголовочном файле "l_intrfc.h" 
и его реализация (в отдельном файле l_impl.cpp) образуют
пространство имен namespace h_list
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <sstream>

#include "l_intrfc_.h"

#define DEFAULT_IFILE_NAME "in"
#define DEFAULT_OFILE_NAME "out"

#define printStr(str) cout<<(str)

using namespace std;

istream *inFile = NULL;
bool readFromFile= false;
ostream *outFile = NULL;
bool printToFile= false;
bool repeat= false;
bool awto = false;
int awtoLim = 0;

void help(){
    cout<<"-h\t\thelp\n";
    cout<<"-A [N]\t\tAuto testing with 0 to N  (ignores -i and -r)\n";
    cout<<"-r\t\tchose to repeat input after compliton. Incompatable with \"-i\"!\n";
    cout<<"-i [file]\t input from file (\""<<DEFAULT_IFILE_NAME<<"\" by default)\n";
    cout<<"-o [file]\t output to file (\""<<DEFAULT_OFILE_NAME<<"\" by default)\n";

}

void setIFile(istream* istr){
    //cin.rdbuf()
    cin.rdbuf((*istr).rdbuf());
    //inFile=istr;
}

void setOFile(ostream* ostr){
    cout.rdbuf((*ostr).rdbuf());
    //outFile=ostr;
}

int parseArgs(int argc, char** argv, string &iFileName, string &oFileName);	//Parses arguments. Returns 1 if program is to be closed



using namespace h_list;


int maxDepth(const lisp s, int recLvl = 0); // Returns max depth of hierarchical list

string genHL(int lvl);//Get generated string Hierarch-List of depth lvl

int awtoInput(lisp &s1);//Auto testing

int main (int argc, char** argv){

	//Variables
    string iFileName;
    string oFileName;

    ofstream oFile;
    ifstream iFile;
	
	lisp s1;
    int _depth; //Result container

	//Parse argsuments
    if(parseArgs(argc,argv,iFileName,oFileName))return 0;

	//File management
    if (printToFile){
        oFile.open(oFileName,ios::out);
        if(!oFile){
            printStr("Cannot open file: "+oFileName+"\n");
            return 1;
        }
        setOFile(&oFile);
    }
    if (readFromFile){
        iFile.open(iFileName);
        if(!iFile){
            printStr("Cannot open file: "+iFileName+"\n");
            return 1;
        }
        setIFile(&iFile);
    }

    
    //Main cycle

    do {

        //Input
        if (awto) {
            awto = !awtoInput(s1);
        } else {
            cout << "Enter hierarchical list(bound wihh brackets. Any standalone symbol is interpritet as an atom):"
                 << endl;
            read_lisp(s1);
        }
        //Echo

        cout << "Input: " << endl;
        write_lisp(s1);
        cout << endl;

        //Process and print
        cout << "Inter=results:\n";
        _depth = maxDepth(s1);
        cout << "Depth: \n" << _depth << endl;

        //Checks

        if(repeat)
        {
            printStr("\nRepeat? [1-Yes|0-No]\n");
            cin.clear();
            int t=0;
            cin >> t;
            repeat = t;
        }
        cout<<endl;

    } while (repeat || awto);

	return 0;
}

int parseArgs(int argc, char** argv, string &iFileName, string &oFileName){
 //Run through all arguments looking for matches. Wrong keys are ignored. Wrong values leads to an undefined behaviour.


    int i=1;


    while(i<argc){

        //if(argc>1){
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
        } else i++;
    }
    if(awto && (readFromFile||repeat)){
        printStr("Warning! -A is incompatable with  -r and -i. These are ignored!\n");
        readFromFile=repeat=false;
    }

    if((readFromFile||printToFile)&&repeat){
        repeat=false;
        printStr("Warning! -i and -o are incompatable with  -r. -r is ignored!\n");
    }

    return 0;
}



int maxDepth(const lisp s, int recLvl)
{
    int depth;// for temporary depth containing
    if(isNull(s)||isAtom(s)){return 0;} // null and atom elements has zero depth
    else
    {
        lisp l = s; //Initial node

        for(int i = 0;i<recLvl;i++)cout<<"\t"; //Inter-result
        write_lisp(l);
        cout<<endl;

        int _maxDepth=maxDepth(l->node.pair.hd,recLvl+1); //Look for max child element depth



        while(!isNull(l->node.pair.tl)) //Hence running through all sub-elements
        {
            l=l->node.pair.tl;  //Take next node


            depth=maxDepth(l->node.pair.hd,recLvl+1);   //Take depth of current element

            _maxDepth=depth>_maxDepth?depth:_maxDepth;  //Default max algo
        }
        for(int i = 0;i<recLvl;i++)cout<<"\t";cout<<_maxDepth+1<<endl; //Inter-result
        return _maxDepth+1;//Current depth is max child depth + self(another 1)
    }
}

string genHL(int lvl){//list lvl deep consists of lvl lists lvl-1 deep. lvl=0 deep list is an '1' atom
    if(lvl)
    {
        string s = "( ";
        for(int i = 0;i<lvl; i++){
            s+=genHL(lvl-1);
            s+=" ";
        }
        s+=" )";
        return s;
    }else{
        return ((string)"1");
    }
}

int awtoInput(lisp &s1){//gens string, turns it into stream, feeds is as an input. last iteration returns 1
    static int n = 0;

    string strg = genHL(n);
    istringstream strst(strg);
    cin.rdbuf(strst.rdbuf());
    read_lisp(s1);
    n++;
    if(n>awtoLim)return 1;
    else return 0;
}
