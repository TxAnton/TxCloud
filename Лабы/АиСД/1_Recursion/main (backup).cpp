#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <string>

using namespace std;

#define ATYPE vector
#define DEFAULT_IFILE_NAME "in"
#define DEFAULT_OFILE_NAME "out"

istream *inFile;
bool readFromFile= false;
ostream *outFile;
bool printToFile= false;
bool repeat= false;
bool awto = false;
int awtoLim = 0;

int parseArgs(int argc, char** argv, string &iFileName, string &oFileName);	//Parses arguments. Returns 1 if program is to be closed
int input(istream *istr,ATYPE<int> &inp);				//Fills int vector from *istr
void printStr(string str);								//Prints string to all necessary outputs
void printColl(ATYPE<int> alpha,int recLvl = 0);		//Prints given collection to all necessary outputs. alpha - collection to print, recLvl - offset
ATYPE<int> phi(ATYPE<int> &alpha,int recLvl = 0);		//Recursively processes alpha
int awtoInput(ATYPE<int> &inp, int lim);                //input function for auto testing

void help(){
    cout<<"-h\t\thelp\n";
    cout<<"-A [N]\t\tAuto testing with 0 to N vector length (ignores -i and -r)\n";
    cout<<"-r\t\tchose to repeat input after compliton. Incompatable with \"-i\"!\n";
    cout<<"-i [file]\t input from file (\""<<DEFAULT_IFILE_NAME<<"\" by default)\n";
    cout<<"-o [file]\t output to file (\""<<DEFAULT_OFILE_NAME<<"\" by default)\n";

}

void setIFile(istream* istr){
    inFile=istr;
}

void setOFile(ostream* ostr){
    outFile=ostr;
}

int main(int argc, char** argv) {

    //Variables
    string iFileName;
    string oFileName;

    ATYPE<int> inp;//input container
    ATYPE<int> res;//result container

    ofstream oFile;
    ifstream iFile;

    bool r = true;
    //Parse arguments
    if(parseArgs(argc,argv,iFileName,oFileName))return 0;

    //Manage files
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

    while(r) {

        //Input
        if(!awto) {
            if (input(readFromFile ? &iFile : &cin, inp)) {
                printStr("Error: Bad input data\n");
                return 1;
            }
        } else {
            if(awtoInput(inp,awtoLim))return 0;
        }

        //Process and print
        printStr("\nInput:");
        res = phi(inp);
        printStr("Result:");
        printColl(res);

        //Checks
        if(awto){
            r= true;
        } else {
            if (repeat) {
                printStr("\nRepeat? [1-Yes|0-No]\n");
                cin.clear();
                int t;
                cin >> t;
                r = t;
                if (r)printStr("\n");
                else printStr("Good bye!\n");
            } else r = false;
        }
    }
    if(printToFile)oFile.close();

    return 0;
}

int parseArgs(int argc, char** argv, string &iFileName, string &oFileName){
    //ATYPE<int> t;

    //bool done=0;
    int i=1;

    //string fileName;

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
            } else awtoLim = 2;
            i++;
        }

        //}
    }
    if(readFromFile&&repeat){
        readFromFile=false;
        printStr("Warning! -i, -r are incompatable. -i is ignored!\n");
    }
    return 0;
}

int input(istream *istr,ATYPE<int> &inp){
    if(!inp.empty())inp.clear();
    //ATYPE<int> inp;
#define INS ( readFromFile?(*inFile):cin )
    int a;

    printStr("Enter integer elements of vector alpha(end with EOF):\n");

    INS>>a;
    //cout<<a<<endl;
    //else cin>>a;

    while(!INS.fail() && !INS.eof()){
        inp.push_back(a);
        INS>>a;
    }
    if(!INS.fail()){inp.push_back(a);return 0;}
    else if(!INS.eof()){return 1;}
    else return 0;
}

int awtoInput(ATYPE<int> &inp, int lim){
    static int n = 0;
    if(!inp.empty())inp.clear();
    if(n<=lim){
        for(int i = 0;i<n;i++){
            inp.push_back(i+1);
        }
        n++;
        return 0;
    }else return 1;
}

void printStr(string str){
    cout<<str;
    if(printToFile&&outFile&&(*outFile))(*outFile)<<str;
}

void printColl(ATYPE<int> alpha,int recLvl) {

    while (recLvl--) {
        cout << "\t ";
        if (printToFile&&outFile) (*outFile) << "\t ";
    }
    for(auto it = alpha.begin();it!=alpha.end();it++){
        cout<<*it<<" ";
        if (printToFile&&outFile) (*outFile) <<*it<<" ";
    }
    cout << endl;
    if (printToFile&&outFile) (*outFile) << endl;
}

ATYPE<int> phi(ATYPE<int> &alpha,int recLvl){

    printColl(alpha,recLvl);

    size_t len=alpha.size();
    if(len<=2){//exit condition
        return alpha;

    }
    else if(!(len&1)){//even
        ATYPE<int> beta(alpha.begin(),alpha.begin()+len/2);
        printStr("B:");
        beta= phi(beta,recLvl+1);
        ATYPE<int> gamma(alpha.begin()+len/2,alpha.end());
        printStr("C:");
        gamma= phi(gamma,recLvl+1);

        ATYPE<int> res(beta);
        res.insert(res.end(),gamma.begin(),gamma.end());
        return res;
    }
    else{//odd
        ATYPE<int> beta(alpha.begin(),alpha.begin()+len/2+1);
        printStr("Ba:");
        beta= phi(beta,recLvl+1);
        ATYPE<int> gamma(alpha.begin()+len/2,alpha.end());
        printStr("aC:");
        gamma= phi(gamma,recLvl+1);

        ATYPE<int> res(beta);
        res.insert(res.end(),gamma.begin(),gamma.end());
        return res;
    }
}
