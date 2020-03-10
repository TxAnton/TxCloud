#include <iostream>
#include <fstream>
#include <sstream>
//#include <tuple>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

#define FILE_INP
//#define DEBUG


#define V_TYPE char
#define W_TYPE double

/*
struct Edge{
    int a;
    int b;
    double cap;
    double flow;
    bool backward;

    bool operator<(const Edge &other) const {
        return (this->a != other.a)?(this->a < other.a):(this->b < other.b);
    }

    bool cmp(const Edge &other) const {
        return (this->a != other.a)?(this->a < other.a):(this->b < other.b);
    }
};
*/

struct HaEdge {
    V_TYPE a;
    V_TYPE b;
    W_TYPE cap;
    mutable  W_TYPE flow;
    bool backward;

    W_TYPE resCap()const{
        return backward?flow:cap-flow;
    }

    bool augmentable() const{
        return backward?(flow!=0):(cap!=flow);
    }

    void augment(std::map<V_TYPE, std::set<HaEdge> > &gr, W_TYPE amount)const {
        if(backward){
            modFlow(-amount);
            gr[b].find({0,a,0,0,false})->modFlow(amount);
        }else{
            modFlow(amount);
            gr[b].find({0,a,0,0,false})->modFlow(-amount);
        }
    }

    void modFlow(W_TYPE amount)const {
        if(backward){
            flow-=amount;
        }else{
            flow+=amount;
        }
    }

    bool operator<(const HaEdge &other) const {//Compare by destination vertex
        return (this->b < other.b);
    }

    bool operator==(const HaEdge &other) const {
        return (this->b == other.b);
    }

    bool cmp(const HaEdge &other) const {

        if(this->b == other.b){
            if(this->backward==other.backward) {
                if (this->cap == other.cap) {
                    return this->flow < other.flow;

                } else {
                    return this->cap < other.cap;
                }
            }else{
                return this->backward<other.backward;
            }
        }else{
            return this->b < other.b;
        }

    }

    static bool cmpRes(const HaEdge &lval, const HaEdge &rval) {
        return (lval.resCap()<rval.resCap());
    }


    std::string toString()const{
        std::ostringstream strs;
        strs<<"("<<a<<" "<<(backward?"<-":"->")<<" "<<b<<" "<<flow<<"/"<<cap<<")";
        return strs.str();
    }

    std::string shortStr()const {
        std::ostringstream strs;
        strs<<a<<(backward?"<--":"-->")<<flow<<"/"<<cap<<"--"<<b;
        return strs.str();
    }
};

std::map<V_TYPE, std::set<HaEdge> > graph;

V_TYPE S;
V_TYPE T;

std::vector<V_TYPE> path;


void quickGreedy() {
    std::set<V_TYPE> visited;
    V_TYPE v = S;

    visited.insert(S);

    std::cout<<v<<std::endl;

    while(v!=T){
        W_TYPE minW = INT32_MAX;
        V_TYPE minV = S;
        for(auto it:graph[v]){
            if(!visited.count(it.b)) {
                if(it.cap < minW){
                    minW=it.cap;
                    minV=it.b;
                }
            }
        }
        std::cout<<minV<<" "<<minW<<std::endl;
        visited.insert(minV);
        v = minV;
        minW=INT32_MAX;
    }
}

W_TYPE getMaxFlow(){
    W_TYPE sum = 0;
    for(auto it:graph[S]){
        sum+=it.flow;
    }
    return sum;
}

void read() {
    int n = 0;
    V_TYPE a;
    V_TYPE b;
    W_TYPE w;
    HaEdge edge;

    std::cin>>n>>S>>T;



    while (n--) {
        std::cin >> a >> b >> w;

        edge = {a, b, w, 0, false};
        graph[a].insert(edge);

        edge = {b, a, w, 0, true};
        graph[b].insert(edge);
    }
}
void write(){
    for(auto it:graph){
        std::cout<<it.first<<" : ";
        for(auto it1:it.second){
            std::cout<<it1.toString()<<" ";
        }
        std::cout<<std::endl;
    }
}

void propperWrite(){
    std::cout<<getMaxFlow()<<std::endl;
    for(auto it:graph){
        for(auto it1:it.second){
            if(!it1.backward)
                std::cout<<it1.a<<" "<<it1.b<<" "<<it1.flow<<std::endl;
        }
    }
}

bool _findPath(){
    std::set<HaEdge> q;
    std::vector<V_TYPE> _path;
    std::set<V_TYPE> visited;
    visited.insert(S);
    bool flag = false;
    bool iterRep = true;
    q.insert({0,S,0,0,false});
    //for(auto it:graph[S]){q.insert(it);visited.insert(it.b);};
    while(iterRep){
        iterRep=false;
        for(auto it:q) {
            for (auto it1:graph[it.b]) {
                if (!q.count(it1) && it1.augmentable() && !visited.count(it1.b)) {
                    q.insert(it1);
                    visited.insert(it1.b);
                    iterRep = true;
                    if (it1.b == T) {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag)break;
        }
    }
    if(flag){

        HaEdge v = {T,0,0,0,false};//*(q.find({0,T,0,0,false}));
        while(v.a!=S){
            _path.push_back(v.a);
            v = *(q.find({0,v.a,0,0,false}));
        }
        _path.push_back(v.a);
        path = std::vector<V_TYPE>(_path.rbegin(),_path.rend());
        return true;
    }else{
        return false;
    }

}

bool findPath() {
    std::set<V_TYPE> visited;
    std::vector<V_TYPE> _path;
    bool flag = true;

    _path.push_back(S);

    auto itInit = graph[_path.back()].begin();

    while(_path.back()!=T){
        flag=false;
        for(auto it=itInit;it!=graph[_path.back()].end();it++){
            if(it->augmentable() && !visited.count(it->b)&&(it->b!=_path[_path.size()!=1?_path.size()-2:0])){
                _path.push_back(it->b);
                visited.insert(it->b);
                flag = true;
                break;
            }
        }
        if(!flag){
            bool backtrack = true;
            //while(backtrack) {
            V_TYPE v = _path.back();
            _path.pop_back();

            if (_path.empty())return false;
            auto it = graph[_path.back()].find({0, v, 0, 0, false});
            it++;
            /*
            if (it != graph[_path.back()].end()){
                backtrack=false;
                _path.push_back(it->b);
                visited.insert(it->b);
            }
             */
            //}
            itInit = it;
        }else{
            itInit = graph[_path.back()].begin();
        }
    }
    path=_path;
    return true;
}

W_TYPE findBottleneck() {
    W_TYPE minW = INT32_MAX;
    for(int i = 1;i<path.size();i++){
        HaEdge edge = *(graph[path[i-1]].find({0, path[i], 0, 0, false}));
        auto rCap  = edge.resCap();
        minW=rCap<minW?rCap:minW;
    }
    return minW;
}

void augmentPath(W_TYPE amount) {
    for(int i = 1;i<path.size();i++){
        (graph[path[i-1]].find({0, path[i], 0, 0, false}))->augment(graph,amount);
    }
}

void printPath(){
    std::cout<<S<<std::endl;
    for(int i = 1;i<path.size();i++){
        std::cout<< (graph[path[i-1]].find({0, path[i], 0, 0, false}))->shortStr()<<std::endl;
    }
}



void ff() {
    bool flag = _findPath();
    W_TYPE bottleNeck = 0;
    while (flag) {
        bottleNeck = findBottleneck();
        augmentPath(bottleNeck);
#ifdef DEBUG
        std::cout<<"AugPath by "<<bottleNeck<<":"<<std::endl;
        printPath();
        write();
#endif
        flag=_findPath();

    }
}


int main() {
#ifdef FILE_INP
    std::ifstream in("/media/anton/E6D8B24FD8B21E2D/Git/txcloud/Labs/s2/Alg/3_NetFlow/in");
    std::cin.rdbuf(in.rdbuf());
#endif
    read();
#ifdef DEBUG
    write();
    //_findPath();
    //printPath();
    //quickGreedy();
#endif
    ff();
    propperWrite();

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}