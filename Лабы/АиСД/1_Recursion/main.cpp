#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <string>

using namespace std;

#define ATYPE vector
#define DEFAULT_FILE_NAME "out"

ostream *outFile;
bool printToFile= false;

int parseArgs(int argc, char** argv, string &fileName);	//Parses arguments. Returns 1 if program is to be closed
int input(istream *istr,ATYPE<int> &inp);				//Fills int vector from *istr
void printStr(string str);								//Prints string to all necessary outputs
void printColl(ATYPE<int> alpha,int recLvl = 0);		//Prints given collection to all necessary outputs. alpha - collection to print, recLvl - offset
ATYPE<int> phi(ATYPE<int> &alpha,int recLvl = 0);		//Recursively processes alpha

void help(){
    cout<<"-h\thelp\n";
    cout<<"-f [file]\t output to file (\""<<DEFAULT_FILE_NAME<<"\" by default)\n";
    cout<<"input from stdin\n";
}

void setOFile(ostream* ostr){
	outFile=ostr;
}

int main(int argc, char** argv) {

    string fileName;

    ATYPE<int> inp;//input container
    ATYPE<int> res;//result container

    ofstream oFile;
    //Parse arguments
    if(parseArgs(argc,argv,fileName))return 0;
    
    if (printToFile){
        oFile.open(fileName,ios::out);
        if(!oFile){
			cerr<<"Cannot open file: "<<fileName<<endl; 
			return 1;
		}
		setOFile(&oFile);
    }

	//Input	
	if(input(&cin,inp)){
		printStr("Error: Bad input data\n");
		return 1;
	}


    //Process and print
    printStr("Input:");
	res=phi(inp);
    printStr("Result:");
    printColl(res);

    if(printToFile)oFile.close();

    return 0;
}

int parseArgs(int argc, char** argv, string &fileName){
	ATYPE<int> t;
	//string fileName;
	if(argc>1){
        if(!((string)argv[1]).compare("-h")){
            help();
            return 1;
        } else if(!((string)argv[1]).compare("-f")){
            printToFile=true;
            if(argc>2){
                fileName=(string)argv[2];
            } else fileName = DEFAULT_FILE_NAME;
        }
    }
	return 0;
}

int input(istream *istr,ATYPE<int> &inp){
	//ATYPE<int> inp;
	
	int a;
	
	printStr("Enter integer elements of vector phi(end with EOF):\n");
	
    cin>>a;

    while(!cin.fail() && !feof(stdin)){
        inp.push_back(a);
        (*istr)>>a;
    }
    if(cin.fail()&&!feof(stdin))return 1;
    else return 0;
}

void printStr(string str){
	cout<<str;
	if(printToFile&&outFile)(*outFile)<<str;
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
