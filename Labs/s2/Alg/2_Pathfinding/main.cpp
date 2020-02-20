#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <list>

#define NUMERIC_NAME
#define DEBUG


#ifdef NUMERIC_NAME
#define NCAST int
#define PRINT_VEC(VEC) for(auto _EL_:(VEC)){std::cout<<_EL_<<"";}std::cout<<std::endl
#else
#define NCAST char
#define PRINT_VEC(VEC)  for(auto _EL_:(VEC)){std::cout<<(char)_EL_<<"";}std::cout<<std::endl
#endif

struct link {
    int destName;
    double weight;

    link(int d, double w) {
        destName = d;
        weight = w;
    }

    bool operator<(const link &other) const {
        return this->destName < other.destName;
    }

    bool cmp(const link &other) const {
        return this->destName < other.destName;
    }
};

std::map<int, std::set<link> > graph;

int start;
int finish;

struct label {//Data for A*
    int name;
    int prev;
    double G;

    double H() const { return G + (int) abs((char) name - (char) finish); }//Heuristic function

    label() {
        this->name = 0;
        this->prev = 0;
        this->G = -1;
    }

    label(int name, int prev, double G) {
        this->name = name;
        this->prev = prev;
        this->G = G;
    }

    bool operator<(const label &other) const {
        return this->H() < other.H();
    };

    int operator-(const label &other) const {
        return this->H() - other.H();
    };

    label &operator=(const label &other) = default;/*{
        this->name = other.name;
        this->prev = other.prev;
        this->G = other.G;
        return *this;
    };*/

    static bool cmoLbPtrs(const label *first, const label *second) {
        return first->H() < second->H();
    }
};


bool cmpLinks(const link &first, const link &second) {
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

        graph[x].insert(link(y, w));

        graph[y].insert(link(x, w));

    }
}


void write() {
    for (auto it:graph) {
        std::cout << (NCAST) it.first << " : ";
        for (auto it1:it.second) {
            std::cout << (NCAST) it1.destName << " w" << it1.weight << "; ";
        }
        std::cout << std::endl;
    }
}

bool _greedy(std::set<int> &visited, std::vector<int> &way) {
    bool flag = false;
    int vtx = *way.rbegin();
    if (vtx == finish)return true;

    std::vector<link> vtxs(graph[vtx].begin(), graph[vtx].end());
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
    visited.erase(vtx);
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
    std::map<int, label> lbs;
    std::vector<label *> q;
    std::vector<int> way;

    bool flag = true;

    int vtx = start;
    label lb = label(vtx, -1, 0);

    lbs[vtx] = (lb);

    q.push_back(&lbs[vtx]);

    while (flag) {
        flag = false;
        for (auto it:graph[vtx]) {
            lb = label(it.destName, vtx, lbs[vtx].G + it.weight);
            if (lbs.count(it.destName)) {
                if (lb.H() < lbs[it.destName].H()) {
                    flag = true;
                    lbs[it.destName] = lb;
                    q.push_back(&lbs[it.destName]);
                    std::stable_sort(q.begin(), q.end(), label::cmoLbPtrs);

#ifdef DEBUG
                    std::cout << "Update lable [Name: " << (NCAST) lb.name << "; Prev: " << (NCAST) lb.prev << "; G: "
                              << lb.G << "; H: " << lb.H() << std::endl;
                    std::cout << "Priority queue:" << std::endl;
                    for (auto it:q) {
                        std::cout << (NCAST) it->name << " : " << it->H() + it->G << "; ";
                    }
                    std::cout << std::endl;
#endif

                }
            } else {
                flag = true;
                lbs[it.destName] = lb;
                q.push_back(&lbs[it.destName]);
                std::stable_sort(q.begin(), q.end(), label::cmoLbPtrs);
#ifdef DEBUG
                std::cout << "Set    lable [Name: " << (NCAST) lb.name << "; Prev: " << (NCAST) lb.prev << "; G: "
                          << lb.G << "; H: " << lb.H() << std::endl;
                std::cout << "Priority queue:" << std::endl;
                for (auto it:q) {
                    std::cout << (NCAST) it->name << " : " << it->H() + it->G << "; ";
                }
                std::cout << "\n------------------------------------" << std::endl;
#endif
            }
            if (lb.name == finish)break;
        }
        if (q.front()->name == vtx)q.erase(q.begin());
        vtx = q.front()->name;
    }
    if (lbs.count(finish)) {
        vtx = finish;
        std::vector<int> rvWay;
        while (vtx != start) {
            rvWay.push_back(vtx);
            vtx = lbs[vtx].prev;
        }
        rvWay.push_back(start);
        way = std::vector<int>(rvWay.rbegin(), rvWay.rend());
    }
    return way;
}


int main() {
#ifdef DEBUG
    std::ifstream in("/media/anton/E6D8B24FD8B21E2D1/Git/txcloud/Labs/s2/Alg/2_Pathfinding/in");
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