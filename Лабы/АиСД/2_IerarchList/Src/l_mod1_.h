//
// Created by anton on 9/17/19.
//

//#ifndef SRC_L_MOD1__H
//#define SRC_L_MOD1__H

#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
//#include "l_intrfc_.h"

#define DEFAULT_IFILE_NAME "in"
#define DEFAULT_OFILE_NAME "out"


using namespace std;

static istream *inFile = NULL;
static bool readFromFile= false;
static ostream *outFile = NULL;
static bool printToFile= false;
static bool repeat= false;
static bool awto = false;
static int awtoLim = 0;

static void help(){
    cout<<"-h\t\thelp\n";
    cout<<"-A \tAuto testing (ignores -r)\n";
    cout<<"-r\t\tchose to repeat input after compliton. Incompatable with \"-i\"!\n";
}

static void setIFile(istream* istr){
    inFile=istr;
}

static void setOFile(ostream* ostr){
    outFile=ostr;
}

static void printStr(string str){
    cout<<str;
    if(printToFile&&outFile&&(*outFile))(*outFile)<<str;
}

static int parseArgs(int argc, char** argv, string &iFileName, string &oFileName){
    //vector<int> t;

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
        } else i++;
    }
    if(readFromFile&&repeat){
        readFromFile=false;
        printStr("Warning! -i, -r are incompatable. -i is ignored!\n");
    }
    return 0;
}

#define PRINT(str) printStr(str)

#define INS ( readFromFile?(*inFile):cin )

//s#endif //SRC_L_MOD1__H
