#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

//#define NUMERIC_NAME
#define DEBUG


#ifdef NUMERIC_NAME
#define PRINT_VEC(VEC) for(auto _EL_:(VEC)){std::cout<<_EL_<<"";}std::cout<<std::endl
#else
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

bool cmpLinks(const link &first, const link &second) {
    return first.weight< second.weight;
}

std::map<int, std::set<link> > graph;

int start;
int finish;

void read() {
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
        //graph[x]=std::set<link>();
        graph[x].insert(link(y, w));
        //graph[y]=std::set<link>();
        graph[y].insert(link(x, w));

    }
}


void write() {
    for (auto it:graph) {
        std::cout << (char) it.first << " : ";
        for (auto it1:it.second) {
            std::cout << (char) it1.destName << " " << it1.weight << "; ";
        }
        std::cout << std::endl;
    }
}

bool _greedy(std::set<int> &visited, std::vector<int> &way) {
    bool flag = false;
    int vtx = *way.rbegin();
    if (vtx == finish)return true;

    std::vector<link> vtxs(graph[vtx].begin(),graph[vtx].end());
    std::sort(vtxs.begin(),vtxs.end(),cmpLinks);

    for (auto it:vtxs) {
        if (!visited.count(it.destName)) {
            visited.insert(it.destName);
            way.push_back(it.destName);

            flag |= _greedy(visited, way);
            if(flag)return true;
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
    _greedy(visited, way);
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
    PRINT_VEC(vec);
    return 0;
}