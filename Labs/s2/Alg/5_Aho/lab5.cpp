#include <iostream>
#include <string>
#include <vector>

using namespace std;

//#define JOKER
#define TASK

#define DEBUG

#ifdef DEBUG
#define BDEBUG
#define CDEBUG
#endif

#define AL_TO_NUM(AL) ( (AL)==J?(k-1):( (AL)>='a'&&(AL)<='z'?(AL)-'a':((AL)>='A'&&(AL)<='Z'?(AL)-'A':(AL)) ) )  //Symbol to index
#define NUM_TO_AL(NUM) ((char)( (NUM)==(k-1)?J:(((NUM)>=0 && (NUM)< k)?((NUM)+'a'):(NUM)) ))                    //Index To symbol

const int k = 27;//Alphabet length(with joker)
struct Vertex {
    int children[k], ix, suffixIx, advanceVertexes[k], par, goodSuffixIx;
    bool flag;
    char symbol;
};
vector<Vertex> bohr;
vector<string> patterns;
char J = -1;//Joker symbol

Vertex createVertex(int p, char c) {//Create and init fields
    Vertex v;
    for (int i = 0; i < k; i++) {
        v.children[i] = v.advanceVertexes[i] = -1;
    }
    v.flag = false;
    v.suffixIx = -1;
    v.par = p;
    v.symbol = c;
    v.goodSuffixIx = -1;
    return v;
}

void bohrInit() {//Init with one vertex
    bohr.push_back(createVertex(0, '\0'));
}

void addString(const string &s) {
    int curLast = 0;
#ifdef BDEBUG
    cout<<"\n/-----------------\\"<<endl;
    cout<<"Adding sample: "<<s<<endl;
#endif
    for (int i = 0; i < s.length(); i++) {//Run through chars
#ifdef BDEBUG
        cout<<"current char: "<<s[i]<<endl;
#endif
        char ch = AL_TO_NUM(s[i]);


        if (bohr[curLast].children[ch] == -1) {//Check if already exist
#ifdef BDEBUG
            cout<<"Adding new edge: "<<curLast<<"{"<<NUM_TO_AL(bohr[curLast].symbol)<<"} -> "<<bohr.size() - 1<<"{"<<NUM_TO_AL(ch)<<"}"<<endl;
#endif
            bohr.push_back(createVertex(curLast, ch));//Make new vertex if not
            bohr[curLast].children[ch] = bohr.size() - 1;
        }
        curLast = bohr[curLast].children[ch];
#ifdef BDEBUG
        cout<<"Current vertex: "<<curLast<<"{"<<NUM_TO_AL(bohr[curLast].symbol)<<"}"<<endl;
#endif
    }
    bohr[curLast].flag = true;
#ifdef BDEBUG
    cout<<"Vertex "<<curLast<<"{"<<NUM_TO_AL(bohr[curLast].symbol)<<"}"<<" marked final"<<endl;
#endif
    patterns.push_back(s);
    bohr[curLast].ix = patterns.size() - 1;

#ifdef BDEBUG
    cout<<"Sample added "<<s<<endl;
    cout<<"\\-----------------/"<<endl;
#endif

}


int getAdvanceVertex(int v, char ch, bool suff = false);

int getSuffixIx(int v) {
#ifdef DDEBUG
    cout<<"Getting Suffix link for"<<v<<"{"<<NUM_TO_AL(bohr[v].symbol)<<"}"<<endl;
#endif
    if (bohr[v].suffixIx == -1)//Yet have none
        if (v == 0 || bohr[v].par == 0)//trivial
            bohr[v].suffixIx = 0;
        else
#ifdef DDEBUG
            cout<<"Advancing from parent"<<endl;
#endif
            bohr[v].suffixIx = getAdvanceVertex(getSuffixIx(bohr[v].par), bohr[v].symbol, true);//Calc from parent's suffix
#ifdef DDEBUG
    cout<<"Suffix link for"<<v<<"{"<<NUM_TO_AL(bohr[v].symbol)<<"}"<<" is"<<bohr[v].suffixIx<<"{"<<NUM_TO_AL(bohr[bohr[v].suffixIx].symbol)<<"}"<<endl;
#endif
    return bohr[v].suffixIx;
}

int getAdvanceVertex(int v, char ch, bool suff) {
    //Advance by char, checking J in bohr
#ifdef CDEBUG
    cout<<"\n/>=>=>=>=>=>=>=>=>\\"<<endl;
    cout<<"Getting advance from vertex "<<v<<"{"<<NUM_TO_AL(bohr[v].symbol)<<"} "<<"by char "<<NUM_TO_AL(ch)<<endl;
#endif
/*
    if(ch == AL_TO_NUM(J)){
        int cl = -1;
        for(int i = 0; i<k;i++){
            if(bohr[v].children[i]!=-1){
                cl = bohr[v].children[i];
            }
        }
    }
*/
    suff = ch == AL_TO_NUM(J);

    if (bohr[v].advanceVertexes[ch] == -1)//Dont have regular advance vertex
        if (bohr[v].advanceVertexes[AL_TO_NUM(J)] == -1 || suff) {//Dont have J advance vertex
            if (bohr[v].children[ch] != -1) {//Have regular child
                bohr[v].advanceVertexes[ch] = bohr[v].children[ch];
            } else if (bohr[v].children[AL_TO_NUM(J)] != -1 && !suff) {//Have J child
                bohr[v].advanceVertexes[ch] = bohr[v].children[AL_TO_NUM(J)];
            } else if(ch == AL_TO_NUM(J)){//Advance by J symbol
                int cl = -1;
                for(int i = 0; i<k;i++){
                    if(bohr[v].children[i]!=-1){
                        cl = bohr[v].children[i];
                    }
                }
                if(cl!=-1){//Hath any child
                    bohr[v].advanceVertexes[ch] = cl;
                }else if (v == 0)//In init vertex
                    bohr[v].advanceVertexes[ch] = 0;
                else {
                    auto sf = getSuffixIx(v);
                    bohr[v].advanceVertexes[ch] = getAdvanceVertex(sf, ch);//Jump to suffix's advance vertex
                }
            } else if (v == 0)//In init vertex
                bohr[v].advanceVertexes[ch] = 0;
            else {
                auto sf = getSuffixIx(v);
#ifdef CDEBUG
                cout<<"jump to suffix "<<sf<<"{"<<NUM_TO_AL(bohr[sf].symbol)<<"} "<<"by char "<<NUM_TO_AL(ch)<<endl;
#endif
                bohr[v].advanceVertexes[ch] = getAdvanceVertex(sf, ch);//Jump to suffix's advance vertex
            }
        } else {//Have J advance vertex
            bohr[v].advanceVertexes[ch] = bohr[v].advanceVertexes[AL_TO_NUM(J)];
        }
#ifdef CDEBUG
    cout<<"Advance from vertex "<<v<<"{"<<NUM_TO_AL(bohr[v].symbol)<<"} "<<"by char "<<NUM_TO_AL(ch)<<" is "<<bohr[v].advanceVertexes[ch]<<"{"<<NUM_TO_AL(bohr[bohr[v].advanceVertexes[ch]].symbol)<<"} "<<endl;
    cout<<"\\>=>=>=>=>=>=>=>=>/"<<endl;
#endif

    return bohr[v].advanceVertexes[ch];

}

int getGoodSuffixIx(int v) {
#ifdef CDEBUG
    cout<<"\n/->->->->->->->->->\\"<<endl;
    cout<<"Getting follow suffix link for vertex "<<v<<"{"<<NUM_TO_AL(bohr[v].symbol)<<"}"<<endl;
#endif
    if (bohr[v].goodSuffixIx == -1) {//Self ones suffixes leading to finals to reduce asymptotic
        int u = getSuffixIx(v);
        if (u == 0)
            bohr[v].goodSuffixIx = 0;
        else
            bohr[v].goodSuffixIx = (bohr[u].flag) ? u : getGoodSuffixIx(u);
    }
#ifdef CDEBUG
    cout<<"Follow suffix link for vertex "<<v<<"{"<<NUM_TO_AL(bohr[v].symbol)<<"} is "<<bohr[v].goodSuffixIx<<"{"<<NUM_TO_AL(bohr[bohr[v].goodSuffixIx].symbol)<<"}"<<endl;
    cout<<"\\->->->->->->->->->/"<<endl;
#endif

    return bohr[v].goodSuffixIx;
}

void follow(int v, int i, vector<pair<int, int>> &occ) {
#ifdef CDEBUG
    cout<<"\nFollow vertex "<<v<<"{"<<NUM_TO_AL(bohr[v].symbol)<<"} for matches"<<endl;
#endif
    for (int u = v; u != 0; u = getGoodSuffixIx(u)) {
        if (bohr[u].flag) {//Final => found
            occ.push_back({i - patterns[bohr[u].ix].length() + 1, bohr[u].ix + 1});
#ifdef CDEBUG
            cout<<"<!> Found match at position "<<i-patterns[bohr[u].ix].length()+1<<" of pattern "<<patterns[bohr[u].ix]<<endl;
#endif
        }
    }
}

vector<pair<int, int>> qcheck(vector<pair<int, int>> occ, const string &s){
    vector<pair<int, int>> res;
    for(pair<int, int> it:occ){
        bool b = true;
        //for(int i = it.first-1; i<it.first+patterns[it.second].length();i++){
        for(int i = 0; i<patterns[it.second-1].length();i++){
            if(i+it.first-1<s.length()&&s[i+it.first-1]!=patterns[it.second-1][i]&&patterns[it.second-1][i]!=J)b=false;
        }
        if(b)res.push_back(it);
    }
    return res;
}

vector<pair<int, int>> findAllOccurrences(const string &s) {
    vector<pair<int, int>> occ;
    int u = 0;
    for (int i = 0; i < s.length(); i++) {
#ifdef CDEBUG
        cout<<"STATE "<<u<<" INPUT "<<s[i]<<" AT POSITION "<<i<<endl;
#endif
        u = getAdvanceVertex(u, AL_TO_NUM(s[i]));
#ifdef CDEBUG
        cout<<"NEW STATE "<<u<<endl;
#endif
        follow(u, i + 1, occ);
    }
    return qcheck(occ,s);
}

void outVecPairs(const vector<pair<int, int>> &occ) {
    for (const pair<int, int> &it:occ) {
#ifdef JOKER
        cout << it.first << endl;
#else
        cout << it.first << " " << it.second << endl;
#endif
    }
}

void task(string s, vector<pair<int, int>> vec) {

#ifdef DEBUG
    cout<<"\nVar 5 individualisation"<<endl;
#endif

    int max = 0;
    for (Vertex i:bohr) {
        int s = 0;
        for (int c:i.children)if (c != -1)s++;
        if (s > max)max = s;
    }
    cout << "Max out-edges from a vertex: " << max << endl;

    cout << "String with patterns removed: " << endl;

    for (int i = 0; i < s.length(); i++) {
        bool b = true;
        for (pair<int, int> p:vec) {
            if (i >= p.first - 1)
                if (i <= p.first + patterns[p.second - 1].length() - 2)
                    b = false;
        }
        if (b)
            cout << s[i];
    }
}

int main() {
    bohrInit();
    string S = "";
    string tmp = "";

#ifdef JOKER
    cin>>S;
    cin>>tmp;
    cin>>J;
    addString(tmp);
#else
    int n;
    cin >> S;
    cin >> n;
    while (n--) {
        cin >> tmp;
        addString(tmp);
    }
#endif

#ifdef DEBUG
    cout<<"Input string: "<<S<<endl;
#ifdef JOKER
    cout<<"Joker symbol: "<<J<<endl;
#endif
#endif


    auto vec = findAllOccurrences(S);
    outVecPairs(vec);

#ifdef TASK
    task(S, vec);
#endif
}
