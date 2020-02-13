#include <iostream>
#include <vector>
#include<time.h>


#define _MAX(x,y) ((x)>(y)?(x):(y))
#define _MIM(x,y) ((x)<(y)?(x):(y))

#define HTR(H)

bool DEBUG = false;

std::vector<std::vector<int> > bestVtx;
std::vector<std::vector<int> > bestMap;
int bestCnt = 0;
long long ops=0;
/*
ESC[ 38;2;⟨r⟩;⟨g⟩;⟨b⟩ m Select RGB foreground color
ESC[ 48;2;⟨r⟩;⟨g⟩;⟨b⟩ m Select RGB background color
 */

std::vector<int> fct(int n){
    std::vector<int> vec;
    for(int i = 1; i <= n; ++i)
    {
        if(n % i == 0)
            vec.push_back(i);
    }
    return vec;
}

void drawMap(std::vector<std::vector<int> > map){

    for(auto it = map.begin();it!=map.end();it++){
        for(auto it1=it->begin();it1!=it->end();it1++){
            std::cout<<(char)(*it1<=9?*it1 + '0':*it1-10 + 'a');
//            std::cout<<(char)(*it1 + '0');
        }
        std::cout<<std::endl;
    }

}

void iterate(int n, std::vector<std::vector<int> > vtx, std::vector<std::vector<int> > map, int cnt = 1, int initSize = 0, int cap = 0) {
    if(bestCnt && cnt>=bestCnt)return;
    if (cap==0)cap = n * n;//Capacity
    //drawMap(map);
    for (int size = initSize > 0 ? initSize : n - 1; size >= 1; size--) {//For all sizes size
        auto vec = fct(n);
        if(vec.size()>2)size = n/vec[1];//Check for prime factors
        for (int i = 0; i <= n - size; i++) {//Starting with each row i
            int occCol = -1;
            for (int col = 0; col < n; col++) {//Through whole horizontal lane col:0..n
                for (int j = i; j < i + size; j++) {//For its full width(vertical) j:0..size ROW - J
                    if (map[j][col] != 0) {
                        occCol = col;
                    }
                    ops++;
                }
                if (col - occCol == size) {//insert shape

                    auto newVtx = vtx;

                    std::vector<int> curVtx;
                    curVtx.push_back(i);
                    curVtx.push_back(occCol + 1);
                    curVtx.push_back(size);

                    if(DEBUG){
                        for(int foo = 0;foo<cnt;foo++){
                            std::cout <<"\t";
                        }
                        std::cout<<curVtx[0]+1<<" "<<curVtx[1]+1<<" "<<curVtx[2]<<std::endl;
                    }


                    newVtx.push_back(curVtx);

                    auto newMap = map;

                    for (int j = i; j < i + size; j++) {//Row
                        for (int k = occCol + 1; k <= col; k++) {//Col
                            newMap[j][k] = cnt;
                        }
                    }
                    //drawMap(newMap);

                    if (cap - size * size > 0)iterate(n, newVtx, newMap, cnt + 1, size, cap - size * size);
                    else {//iterations are done
                        if (bestCnt == 0 || cnt < bestCnt) {
                            bestCnt = cnt;
                            bestMap = newMap;
                            bestVtx = newVtx;
                            if(DEBUG){
                                for(int foo = 0;foo<cnt;foo++){
                                    std::cout <<"\t";
                                }
                                std::cout<<"New Best"<<std::endl;
                            }
                        }
                        return;
                    }
                    if(vec.size()>2&&bestCnt == vec[1]*vec[1])return;//Check for prime factors
                    if(size==1)return;
                }else if(col - occCol == 2*size)return;

            }
        }
    }
}

void backtrack(int n) {
    std::vector<std::vector<int> > map;
    std::vector<std::vector<int> > vtx;
    bestCnt = 0;
    for (int i = 0; i < n; i++) {
        std::vector<int> tmp(n, 0);
        map.push_back(tmp);
    }
    if(DEBUG)std::cout <<"Interresults:"<< std::endl;
    iterate(n,vtx,map);
    std::cout << std::endl;

}

int main() {
    int n=5;
    std::cin>>n;

    //for(int n = 5; n<6; n++) {
        std::cout << "Here we go!\t\t" << n << std::endl;
        auto tim = time(0);
        backtrack(n);
        tim = time(0) - tim;
        std::cout << "time:\t\t\t" << tim << std::endl;
        std::cout << "num of sqares\t" << bestCnt << std::endl;
        std::cout << "num of ops\t\t" << ops << std::endl;
        //std::cout << bestVtx[0][0]<<bestVtx[0][1]<<bestVtx[0][2] << std::endl;
        for(auto it = bestVtx.begin();it!=bestVtx.end();it++){
            std::cout<<(*it)[0]+1<<" "<<(*it)[1]+1<<" "<<(*it)[2]<<std::endl;
        }
        std::cout << std::endl;
        drawMap(bestMap);
        bestCnt = 0;
        ops = 0;
        std::cout <<"======================================="<< std::endl;
    //}
    return 0;
}