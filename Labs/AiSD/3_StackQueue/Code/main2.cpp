#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <sstream>

#include "st_interf2.h"

#define DEFAULT_IFILE_NAME "in"
#define DEFAULT_OFILE_NAME "out"

#define BUF_SIZE 1024

//#define printStr(str) cout<<(str)

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
    cout<<"-A\t\tAuto reading input line by line\n";
    cout<<"-r\t\tchose to repeat input after compliton. Incompatable with \"-i\"!\n";
    cout<<"-i [file]\t input from file (\""<<DEFAULT_IFILE_NAME<<"\" by default)\n";
    cout<<"-o [file]\t output to file (\""<<DEFAULT_OFILE_NAME<<"\" by default)\n";

}

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
char bracketPair(char b);
int processStr(string str);
//char processStr(string str,int &i,int reclvl=0);
void printStr(string str);
int input(string &inp);
using namespace st_modul2;


int main (int argc, char** argv ) {
    ///Variables
    string iFileName;
    string oFileName;

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

        string str;
        printStr("\n");
        if(!awto)printStr("Enter bracket sequense:\n");

        if(input(str)){
            if(awto)return 0;
            else {printStr("Input failt!");return 0;}
        }

        printStr("Input: \n" + str + "\n");

        ///Processing with inter-results output

        printStr("Inter results:\n");
        //int i = 0;
        int c = processStr(str);
/*
        printStr("Result:\n");
        if (c == 0) {
            printStr("Correct!\n");
        } else if (c == 1) {
            printStr(str.substr(0, i + 1) + " <<ERROR HERE!" + "\n");
            string o = "";
            o += str[i];
            printStr("Unexpected '" + o + "'\n");
        } else {
            if (i == str.length()){
                string o = "";
                o += c;
                printStr("Bracket '"+o+"' left unclosed\n");
            }
            else {
                printStr(str.substr(0, i + 1) + " <<ERROR HERE!" + "\n");
                string o = "";
                o += c;//bracketPair(c);
                string q = "";
                q += str[i];
                printStr("Expected '" + o + "' while got '" + q + "'");
            }
        }
*/
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
        } else i++;
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

int isOpenBracket(char b){
    return b=='('||b=='['||b=='{';
}

int isCloseBracket(char b){
    return b==')'||b==']'||b=='}';
}

char bracketPair(char b){
    switch (b){
        case '(':{
            return ')';
        }
        case ')':{
            return '(';
        }
        case '[':{
            return ']';
        }
        case ']':{
            return '[';
        }
        case '{':{
            return '}';
        }
        case '}':{
            return '{';
        }
    }
}

int processStr(string str){
    Stack<char> s;
    int len=str.length();
    int pi=0;
    for(int i=0;i<len;i++){
        while(i<len && !isOpenBracket(str[i]) && !isCloseBracket(str[i]))i++;///Skip all none-brackets
        if(isOpenBracket(str[i])) {///As we met open bracket...
            s.push(str[i]);//push
            pi=i;
            for(int i=0; i<s.topOfStack;i++){///ECHO PUSH
                string o="";o+=s.vec[i];
                printStr(o+" ");
            }
            string o="";o+=s.top();
            printStr("<< "+ o+"\n");
        }else if(isCloseBracket(str[i])){///As we met close bracket...

            if(s.isEmpty()){
                ///ERR UNEXPECTED
                printStr(str.substr(0, i + 1) + " <<ERROR HERE!" + "\n");
                string o = "";
                o += str[i];
                printStr("Unexpected '" + o + "'\n");
                s.destroy();
                return 0;
            }
            if(s.top()==bracketPair(str[i])){///... korrekt bracket...
                for(int i=0; i<s.topOfStack;i++){///ECHO POP
                    string o="";o+=s.vec[i];
                    printStr(o+" ");
                }
                string o="";o+=s.pop2();//pop
                printStr(">> "+ o+" <"+str[i]+">\n");
            }else{///wrong bracket
                ///ERROR WRONG
                printStr(str.substr(0, i + 1) + " <<ERROR HERE!" + "\n");
                string o = "";
                o += bracketPair(s.top());//bracketPair(c);
                string q = "";
                q += str[i];
                printStr("Expected '" + o + "' while got '" + q + "'\n");
                s.destroy();
                return 0;
            }
        }
    }
    if(!s.isEmpty()){
        ///ERROR LEFT
        printStr(str.substr(0, pi + 1) + " <<ERROR HERE!" + "\n");
        string o = "";
        o += s.top();
        printStr("Bracket '"+o+"' left unclosed\n");

    }else{
        printStr("Correct!\n");
    }
}
/*
char processStr(string str,int &i, int reclvl){

    int len=str.length();///Needed meny times

    Stack<char> s;///Stack to work with

    while(1){///Main cycle within one recursion level
        //int i = st;
        while(i<len && !isOpenBracket(str[i]) && !isCloseBracket(str[i]))i++;///Skip all none-brackets
        if(i==len){///If the string is done...
            if(s.isEmpty())return 0;///...and stack is empty - oll is korrect!
            else return s.ttop();///...and stack is not empty - it has on top unclosed bracket

        }

        if(isOpenBracket(str[i])){///As we met open bracket...
            for (int j = 0; j < reclvl; ++j)printStr("\t");
            string p="";p+=str[i];///ECHO OPEN BRACKET
            printStr(p);
            printStr("\n");

            s.push(str[i]);
            i++;
            char c = processStr(str,i,reclvl+1);///
            if(c!=1&&c!=0)return bracketPair(c);///...we dive into next lvl recursion
        } else if(isCloseBracket(str[i])){///As we met close bracket...
            if()

            if(!s.isEmpty()&&s.top()==bracketPair(str[i])){///... korrekt bracket...

                for (int j = 0; j < reclvl; ++j)printStr("\t");
                string p="";p+=str[i];///ECHO CLOSE BRACKET
                printStr(p);
                printStr("\n");

                i++;
                s.pop();///...open and close brackets are inter-annihilated


                //if(s.isEmpty())return 0;
            } else{///... wrong bracket or none oppened...

                for (int j = 0; j < reclvl; ++j)printStr("\t");
                //string p="";p+=str[i];
                printStr("<-");///ECHO CLOSE BRACKET
                printStr("\n");

                if(s.isEmpty()){return 1;}///...none oppened so far - retur deff err code
                else if(s.top()!=bracketPair(str[i])){///Met wrong close bracket
                        return s.ttop();///Return bracket we expected to be closed; str[i] is what we actually got. INNER RETURN
                    }

            }
        }
    }
}
*/
void printStr(string str){
    cout<<str;
    if(printToFile&&outFile&&(*outFile))(*outFile)<<str;
}

int input(string &inp){
#define INS ( readFromFile?(*inFile):cin )
    if(INS.eof())return 1;
    char *c=new char[BUF_SIZE];
    if(!c)return 1;
    INS.getline(c,BUF_SIZE-1,'\n');
    //INS.get();
     if(INS.fail()&&!INS.eof())
        return 1;
    inp=c;
    return 0;
}
