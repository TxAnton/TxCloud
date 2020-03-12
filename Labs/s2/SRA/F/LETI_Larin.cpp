/*
 * By: larin.an10n@gmail.com
 */

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define ITOC(VAL) ((char)((VAL)<=35?((VAL)<=9?(VAL) + '0':(VAL)-10 + 'a'):(VAL)-36 + 'A'))

#define LIM 100

double p(double n) {
    if (n < 0)return 0;
    else if (n <= 1)return 1;

    double s = 0;

    for (int m = 1; m < LIM; m++) {
        s += (m & 1 ? 1 : -1) *
             (p(n - (((double) m * (3 * (double) m - 1)) / 2)) + p(n - (((double) m * (3 * (double) m + 1)) / 2)));
    }
    return s;
}

void printJ(vector<vector<int>> J, bool asChar = true) {//Печать таблицы Юнга
    int size = 0;
    for (auto it:J) {
        if (it.size() > size)size = it.size();
    }


    for (int row = size - 1; row >= 0; row--) {//Up to down
        for (int col = 0; col < J.size(); col++) {//Lef to right
            if (J[col].size() > row) {
                if (asChar) {
                    cout << ITOC(J[col][row]);
                } else {
                    cout << J[col][row] << "\t";
                }

            } else cout << ' ';
        }
        cout << endl;
    }
}

void printSS(vector<vector<int>> SS) {//Печать списка простых подпоследовательностей
    int i = 0;
    for (auto it:SS) {
        cout << "SS[" << ++i << "]:" << endl;
        for (auto it1:it)cout << it1 << " ";
        cout << endl;
    }
}

tuple<vector<vector<int>>, vector<vector<int>>, vector<vector<int>>> RSK(vector<int> perm, bool echo = false) {
    /*
     * Преобразование RSK
     * На вход:
     * perm - входная перестановка
     * echo - вывод промежуточных данных
     * На выход:
     * <Таблица Q,Таблица P, список простых подпоследовательностей>
     */
    int n = perm.size();
    vector<vector<int>> J;
    vector<vector<int>> JJ;
    vector<vector<int>> SS;
    std::vector<int> tmp;
    int val;
    int col;
    /*for (int i = 0; i < n; i++) {
        J.push_back(tmp);
    }*/

    for (int id = 0; id < perm.size(); id++) {
        val = perm[id];
        col = 0;
        if (J.size() <= col)J.push_back(tmp);
        if (JJ.size() <= col)JJ.push_back(tmp);
        bool flag = true;
        while (flag) {
            flag = false;
            for (int i = 0; i < J[col].size(); i++) {//Iterate through current column
                if (val < J[col][i]) {
                    int t = J[col][i];
                    J[col][i] = val;
                    val = t;
                    flag = true;
                    if (col == 0) {
                        if (SS.size() <= J[0].size())SS.resize(J[0].size());
                        SS[i].push_back(J[col][i]);
                    }
                    col++;
                    if (J.size() <= col)J.push_back(tmp);
                    if (JJ.size() <= col)JJ.push_back(tmp);
                    break;
                }

            }
            if (!flag) {
                J[col].push_back(val);
                JJ[col].push_back(id + 1);
                if (col == 0) {
                    if (SS.size() <= J[0].size())SS.resize(J[0].size());
                    SS[J[0].size() - 1].push_back(val);
                }
            }
        }
        if (echo) {
            cout << id + 1 << ":" << endl;
            printJ(J);
            cout << endl;
        }
    }
    return make_tuple(J, JJ, SS);
}

vector<int> longestAscendingSS(vector<int> SS, vector<int> cur = vector<int>()) {
    /*
     * Максимальная возрастающая подпоследовательность
     * На вход:
     * SS - последовательность
     * cur - последовательность на текущем витке рекурсии
     * На выход:
     * Подпоследовательность в порядке убывания
     */
    bool flag = false;
    vector<int> longest;
    for (auto it = SS.begin(); it != SS.end(); it++) {
        if (cur.empty() || (*it) < cur.back()) {
            flag = true;
            cur.push_back(*it);
            vector<int> temp = longestAscendingSS(vector<int>(it + 1, SS.end()), cur);
            cur.pop_back();
            if (longest.empty() || temp.size() > longest.size())longest = temp;
        }
    }
    if (!flag)return cur;
    return longest;
}


int main() {
/*
    vector<int> perm = {13,19,9,16,14,4,17,18,11,7,8,1,2,5,15,20,12,3,10,6};//perm = {6,7,5,4,10,1,8,9,2,3};


    auto t = RSK(perm);
    cout<<"P:"<<endl;
    printJ(get<0>(t),false);
    cout<<endl<<"Q:"<<endl;
    printJ(get<1>(t),false);
    cout<<endl<<"SS:"<<endl;
    printSS(get<2>(t));
    cout<<endl;

    cout<<"LongestSS:"<<endl;
    auto lss=longestAscendingSS(perm);
    for(auto it:lss)cout<<it<<" ";
*/
/*
    cout<<"======================================================"<<endl;
    perm = {13,19,9,16,14,4,17,18,11,7,8,1,2,5,15,20,12,3,10,6};
    t = RSK(perm);
    cout<<"P:"<<endl;
    printJ(get<0>(t));
    cout<<endl<<"Q:"<<endl;
    printJ(get<1>(t));
    cout<<endl<<"SS:"<<endl;
    */
    //vector<vector<int>> J = {{1,2,3,7},{4,6,8},{5,9},{10}};
    //printJ(J);


    for (int i = 0; i < 11; i++) {
        std::cout << i << " " << p(i) << std::endl;
    }
    return 0;
}