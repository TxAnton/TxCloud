#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <list>
#include <climits>


#define LOC


#ifdef LOC
    //#define NUMERIC_NAME
    #define DEBUG
    #define FILE_INP
#endif
//#define NUMERIC_NAME
//#define DEBUG
//#define FILE_INP

#ifdef NUMERIC_NAME
    #define NCAST int
#else
    #define NCAST char
#endif

#define PRINT_VEC(VEC) for(auto _EL_:(VEC)){std::cout<<(NCAST)_EL_<<"";}std::cout<<std::endl


/*
Комменты
Ясность
 */

struct Link {
    int destName;
    double weight;

    Link(int d, double w) {
        destName = d;
        weight = w;
    }

    bool operator<(const Link &other) const {
        return this->destName < other.destName;
    }

    bool cmp(const Link &other) const {
        return this->destName < other.destName;
    }
};

std::map<int, std::set<Link> > graph;

int start;
int finish;

struct Label {//Data for A*
    int name;
    int prev;
    double G;

    double H() const { return (int) abs((char) name - (char) finish); }//Heuristic function

    double F() const { return G + H(); }//F function

    Label() {
        this->name = 0;
        this->prev = 0;
        this->G = -1;
    }

    Label(int name, int prev, double G) {
        this->name = name;
        this->prev = prev;
        this->G = G;
    }

    bool operator<(const Label &other) const {
        return this->F() < other.F();
    };

    int operator-(const Label &other) const {
        return this->F() - other.F();
    };

    Label &operator=(const Label &other) = default;/*{
        this->name = other.name;
        this->prev = other.prev;
        this->G = other.G;
        return *this;
    };*/

    static bool cmpLbPtrs(const Label *first, const Label *second) {
        return  first->F() < second->F();//first->F() == second->F()?(first->name<second->name):(first->F() < second->F());
    }
};


bool cmpLinks(const Link &first, const Link &second) {
    return first.weight < second.weight;
}


void read() {// Graph data from stdin

    //Read init and finish vertexes

#ifdef NUMERIC_NAME
    std::cin>>start>>finish;
#else
    char a;
    char b;
    std::cin >> a >> b;
    start = int(a);
    finish = (int) b;
#endif
    while (!std::cin.eof()) {
        int x, y;
        double w;
#ifdef NUMERIC_NAME
        std::cin>>x>>y;
#else
        std::cin >> a >> b;
        x = (int) a;
        y = (int) b;
#endif
        std::cin >> w;

        //Init graph

        graph[x].insert(Link(y, w));

        //graph[y].insert(Link(x, w));

    }
}


void write() {
    for (auto it:graph) {
        std::cout << (NCAST) it.first << " - ";
        for (auto it1:it.second) {
            std::cout << (NCAST) it1.destName << ":" << it1.weight << " ; ";
        }
        std::cout << std::endl;
    }
}
/* int _greedy(std::set<int> &visited, std::vector<int> &way,int weight=0) {


    int _weight = -1;
    int minWeight = INT_MAX;
    std::vector<int> _way;
    std::vector<int> _minWay;
    std::set<int> _visited;
    std::set<int> _minVisited;

    bool flag = false;
    int vtx = way.back();// *way.rbegin();
    if (vtx == finish)return true;

    std::vector<Link> vtxs(graph[vtx].begin(), graph[vtx].end());
    std::sort(vtxs.begin(), vtxs.end(), cmpLinks);

    Link pr = {0,-1};

    for (auto it:vtxs) {
        if (flag && it.weight!=pr.weight){
            break;
        }

#ifdef DEBUG
        std::cout << "[Concider] " << (NCAST) it.destName << " of weight " << it.weight << std::endl;
#endif
        if (!visited.count(it.destName)) {
#ifdef DEBUG
            std::cout << "<Visit>    " << (NCAST) it.destName << " of weight " << it.weight << std::endl;
#endif

            visited.insert(it.destName);
            //way.push_back(it.destName);
            _visited.clear();
            _visited.insert(visited.begin(),visited.end());
            _way.clear();
            _way.push_back(it.destName);
            _weight = _greedy( _visited, _way,it.weight);
            if(_weight!=-1){
                flag=true;
                if(_weight<minWeight){
                    _minWay=_way;
                    _minVisited=_visited;
                }
                minWeight=minWeight<_weight?minWeight:_weight;
            }
            //flag |= _greedy(visited, way);
            pr = it;

            //if (flag)return true;
        }
    }
    if(flag){
        way.insert(way.begin(),_minWay.begin(),_minWay.end());
        visited.insert(_minVisited.begin(),_minVisited.end());
        return weight+minWeight;
    }

    way.pop_back();
#ifdef DEBUG
    std::cout << "<Leave>    " << (NCAST) vtx << " Current:  "<< (!way.size()?"None\n!":"") << way.back()<<std::endl;
#endif

    //visited.erase(vtx);
    return -1;

}

 */


int _greedy(std::set<int> &visited, std::vector<int> &way) {


    bool flag = false;//
    int vtx = way.back();// current vertex
    if (vtx == finish)return true;

    std::vector<Link> vtxs(graph[vtx].begin(), graph[vtx].end());//Verexes list
    std::sort(vtxs.begin(), vtxs.end(), cmpLinks);

    for (auto it:vtxs) {

#ifdef DEBUG
        std::cout << "[Concider] " << (NCAST) it.destName << " of weight " << it.weight << std::endl;
#endif
        if (!visited.count(it.destName)) {
#ifdef DEBUG
            std::cout << "<Visit>    " << (NCAST) it.destName << " of weight " << it.weight << std::endl;
#endif

            visited.insert(it.destName);
            way.push_back(it.destName);

            flag |= _greedy(visited, way);

            if (flag)return true;
        }
    }
    way.pop_back();
#ifdef DEBUG
    std::cout << "<Leave>    " << (NCAST) vtx << " Current:  "<< (!way.size()?"None\n!":"") << (NCAST)way.back()<<std::endl;
#endif

    //visited.erase(vtx);
    return false;

}

std::vector<int> greedy() {
    std::set<int> visited;
    std::vector<int> way;
    way.push_back(start);
    visited.insert(start);
    if (!_greedy(visited, way)){std::cerr << "No Way!\n";exit(0);}
    return way;
}

std::vector<int> AStar() {
    std::map<int, Label> labels;
    std::vector<Label *> q;
    std::vector<int> way;

    bool flag = true;

    int vtx = start;//current vertex
    Label lb = Label(vtx, -1, 0);//current label

    labels[vtx] = (lb);
    q.push_back(&labels[vtx]);

    while (!q.empty()) {
#ifdef DEBUG
        std::cout << "Deque vertex " << (NCAST) vtx <<std::endl;
        std::cout << "Priority queue:" << std::endl;
        for (auto it:q) {
            std::cout << (NCAST) it->name << " : " << it->F()<< "; ";
        }
        std::cout << "\n------------------------------------" << std::endl;
#endif
        vtx = q.front()->name;
        if(vtx==finish)break;
        q.erase(q.begin());
        flag = false;
        for (auto it:graph[vtx]) {
            lb = Label(it.destName, vtx, labels[vtx].G + it.weight);
            if (labels.count(it.destName)) {//label exists; updating
                if (lb.G < labels[it.destName].G) {
                    flag = true;
                    labels[it.destName] = lb;

                    q.push_back(&labels[it.destName]);
                    std::stable_sort(q.begin(), q.end(), Label::cmpLbPtrs);

#ifdef DEBUG
                    std::cout << "Update lable [Name: " << (NCAST) lb.name << "; Prev: " << (NCAST) lb.prev << "; G: "
                              << lb.G << "; F: " << lb.F() << std::endl;
                    std::cout << "Priority queue:" << std::endl;
                    for (auto it:q) {
                        std::cout << (NCAST) it->name << " : " << it->F()<< "; ";
                    }
                    std::cout << "\n------------------------------------" << std::endl;
#endif

                }
            } else {//new label
                flag = true;
                labels[it.destName] = lb;
                q.push_back(&labels[it.destName]);
                std::stable_sort(q.begin(), q.end(), Label::cmpLbPtrs);
#ifdef DEBUG
                std::cout << "Set    lable [Name: " << (NCAST) lb.name << "; Prev: " << (NCAST) lb.prev << "; G: "
                          << lb.G << "; F: " << lb.F() << std::endl;
                std::cout << "Priority queue:" << std::endl;
                for (auto it:q) {
                    std::cout << (NCAST) it->name << ":" << it->F() << " ; ";
                }
                std::cout << "\n------------------------------------" << std::endl;
#endif
            }
            //if (lb.name == finish)break;
        }

        //if (q.front()->name == vtx)q.erase(q.begin());
//        vtx = q.front()->name;

    }
    if (labels.count(finish)) {
        vtx = finish;
        std::vector<int> rvWay;
        while (vtx != start) {
            rvWay.push_back(vtx);
            vtx = labels[vtx].prev;
        }
        rvWay.push_back(start);
        way = std::vector<int>(rvWay.rbegin(), rvWay.rend());
    }
    return way;
}


int main() {
#ifdef FILE_INP
    std::ifstream in("/media/anton/E6D8B24FD8B21E2D/Git/txcloud/Labs/s2/Alg/2_Pathfinding/in");
    std::cin.rdbuf(in.rdbuf());
#endif
    read();
#ifdef DEBUG
    write();
#endif
    auto vec = greedy();
    //auto vec = AStar();
    PRINT_VEC(vec);
    return 0;
}