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

#include <cctype>

using namespace std;

void setIFile(istream* istr){
    //cin.rdbuf()
    cin.rdbuf((*istr).rdbuf());
    //inFile=istr;
}

void setOFile(ostream* ostr){
    cout.rdbuf((*ostr).rdbuf());
    //outFile=ostr;
}



using namespace h_list;


int checkLogExpr(lisp& lsp);

int maxDepth(const lisp s, int recLvl = 0); // Returns max depth of hierarchical list

string genHL(int lvl);//Get generated string Hierarch-List of depth lvl

int awtoInput(lisp &s1);//Auto testing

int main (int argc, char** argv){

    string initInput;

    string processedInput;

    lisp lsp;

    char* cstr = (char*)malloc(sizeof(char)*STR_LEN);

    cin.getline(cstr,STR_LEN);

    initInput.insert(0,cstr);


    int c = OP_LEN;
    for(string::const_iterator it = initInput.begin();it!=initInput.end();it++){
        switch (*it) {
            case '(':
            case ')':
            {
                processedInput.append(" ");
                processedInput+=(*it);
                processedInput.append(" ");

                c = OP_LEN;
                break;
            }
            case ' ':
                c = OP_LEN;
                processedInput+=(*it);
                break;
            default:
            {
                c--;
                processedInput+=(*it);
                break;
            }
        }
        if(!c){
            //READ SOMETHING TOO LONG;  ERROR HERE
            cout<<"ACHTUNG\n";
            for(string::const_iterator it1 = initInput.begin(); it1!=it;it1++){
                cout<<*it1;
            }
            exit(0);
        }
    }

    cout<<"Processed:\n"<<processedInput<<endl;

    stringstream strStream(processedInput);

    setIFile(&strStream);

    read_lisp(lsp);

    cout<<"Converted to hierarch list:\n";

    write_lisp(lsp);

    int q = checkLogExpr(lsp);

    if(q){
        cout<<"\nError\n";
    }else{
        cout<<"\nRight\n";
    }



//    read_lisp();


	return 0;
}

int checkLogExpr(lisp& lsp)
{
    cout<<"\nChecking expr:"<<endl;
    write_lisp(lsp);
    cout<<endl;


    if(isAtom(lsp)){
        char* atom = getAtom(lsp);

        if(!strcmp(atom,"AND") || !strcmp(atom,"OR") || !strcmp(atom,"XOR") || !strcmp(atom,"NOT"))//either of those
        {
            //SINGLE OPERATOR WITH NO ARGS
            return 1;
        }
        else
        {
            if(strlen(atom)==1)
            {
                if(isalpha(atom[0]) || atom[0] == '0' || atom[0] == '1' )
                {
                    //Single symbol or number 0/1- correct
                    return 0;
                }
                else
                {
                    //Wrong: wierd single symbol
                    return 1;
                }

            }
            else
            {
                //Wrong: ARGUMENT LONGER THAN 1
                return 1;
            }
        }
    }

    if(!isAtom(head(lsp))){
        //Wrong: expression doesnt starts with an operator
        return 1;
    }

    char* headAtom = getAtom(head(lsp));
    if(!strcmp(headAtom,"AND") || !strcmp(headAtom,"OR") || !strcmp(headAtom,"XOR"))
    {
        //AND OR or XOR
        //Check 2 valid args
        lisp tail1 = tail(lsp);
        //Check 1 valid arg
        if(isNull(tail1))
        {
            //Wrong: AND/OR/XOR with no arguments
            return 1;
        }

        lisp tail2 = tail(tail1);

        if(isNull(tail2)){
            //Wrong: AND/OR/XOR with only 1 arg
            return 1;
        }

        if(!isNull(tail(tail2))){
            //Wrong: AND/OR/XOR with more than 2 args
            return 1;
        }

        //Check both args
        lisp arg1 = head(tail1);
        lisp arg2 = head(tail2);
        if (checkLogExpr( arg1 ) != 0){
            //Wrong: wrong first argument
            return 1;
        }

        if(checkLogExpr( arg2 ) != 0){
            //Wrong: wrong second argument
            return 1;
        }



        return 0;//Oll Korrect
    }
    else if( !strcmp(headAtom,"NOT") )
    {
        lisp tail1 = tail(lsp);
        //Check 1 valid arg
        if(isNull(tail1))
        {
            //Wrong: NOT with no arguments
            return 1;
        }
        if(!isNull(tail(tail1))){
            //Wrong: NOT has more than 1 arg
            return 1;
        }

        //Check 1st arg correctness
        lisp arg1 = head(tail1);
        if (checkLogExpr( arg1 ) != 0){
            //Wrong: wrong first argument
            return 1;
        }

        return 0; //Oll Korrect
    }

    //Wrong: head is not an operator
    return 1;


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
