/*
 * By: larin.an10n@gmail.com
 */

#include <iostream>
#include <vector>
#include <tuple>
#include <cassert>

using namespace std;

#define ITOC(VAL) ((char)((VAL)<=35?((VAL)<=9?(VAL) + '0':(VAL)-10 + 'a'):(VAL)-36 + 'A'))

#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))

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
        if (cur.empty() || (*it) > cur.back()) {
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

vector<int> longestDescendingSS(vector<int> SS, vector<int> cur = vector<int>()) {
    /*
     * Максимальная убывающая подпоследовательность
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
            vector<int> temp = longestDescendingSS(vector<int>(it + 1, SS.end()), cur);
            cur.pop_back();
            if (longest.empty() || temp.size() > longest.size())longest = temp;
        }
    }
    if (!flag)return cur;
    return longest;
}

vector<int> revRSK(vector<vector<int>> P, vector<vector<int>> Q) {
    vector<int> perm;

    while (!Q.empty()) {
        int cRow = 0;
        int cCol = 0;
        for (int col = 0; col < Q.size(); col++) {
            for (int row = 0; row < Q[col].size(); row++) {
                if (Q[col][row] > Q[cCol][cRow]) {
                    cCol = col;
                    cRow = row;
                }
            }
        }//Q[cCol][cRow]
        int val = P[cCol][cRow];
        P[cCol].pop_back();
        Q[cCol].pop_back();
        if (P[cCol].empty()) {
            P.pop_back();
            Q.pop_back();
        }
        cCol--;
        bool flag = true;
        while (flag) {
            //cRow cCol - val to be moved
            flag = false;

            if (cCol == -1) {
                perm.push_back(val);
                flag = false;
                break;
            } else {
                flag = true;
                for (int seek = Q[cCol].size() - 1; seek >= 0; seek--) {
                    if (P[cCol][seek] < val) {
                        int t = val;
                        val = P[cCol][seek];
                        P[cCol][seek] = t;
                        cCol--;
                        break;
                    }
                }
            }
        }
        //Q.clear();
    }
    return vector<int>(perm.rbegin(), perm.rend());
}

void normalizeJDiagram(vector<vector<int>>& J){
    if(J.empty()||J[0].empty())return;
    int x = J[0][0]-1;
    if(x){
        for(auto& it:J){
            for(auto& it1:it){
                it1-=x;
            }
        }
    }
}

vector<vector<int>> nullCopy(vector<vector<int>> src){
    vector<vector<int>> J;
    for(auto it:src){
        J.push_back(vector<int>(it.size(),0));
    }
    return J;
}

tuple<int,int,int> schutzenbergerIteration(vector<vector<int>> &J, bool normalize = false, bool preserveShape = false){//{col,row,val}
    if(J.empty()||J[0].empty())return make_tuple(-1, -1, -1);

    bool flag = true;
    int col=0,row=0,val = -1;

    int n = 0;//Size
    for(auto it:J)n+=it.size();

    while(flag) {
        int cCol = col;
        int cRow = row;
        flag = false;
        bool r1 = J[col].size()>row+1;//There is a cell higher
        bool c1 = J.size()>col+1 && J[col+1].size()>row;
        if(c1){
            flag = true;
            if(r1){
                if(J[col][row+1] < J[col+1][row]){
                    row++;
                }else{
                    col++;
                }
            }else{
                col++;
            }
        }else if(r1){
            flag = true;
            row++;
        } else{
            flag = false;
        }

        if(flag){
            J[cCol][cRow] = J[col][row];//Slide element
        }else{




            val = J[cCol][cRow];//Work on last cell
            if(preserveShape) {
                J[cCol][cRow] = n + 1;
            }else{
                if(J[cCol].size()==1){
                    J.pop_back();
                }else{
                    J[cCol].pop_back();
                }
            }
        }
    }
    if(normalize)normalizeJDiagram(J);
    return make_tuple(col, row, val);
}

vector<vector<int>> schutzenbergerInvolution(vector<vector<int>> J){
    auto JJ = nullCopy(J);

    int n = 0;//Size
    for(auto it:J)n+=it.size();

    int i = n;
    while(!J.empty()){
        auto res = schutzenbergerIteration(J);
        JJ[get<0>(res)][get<1>(res)]=i--;
    }
    return JJ;
}

void tasks(){
    vector<int> perm = {13, 19, 9, 16, 14, 4, 17, 18, 11, 7, 8, 1, 2, 5, 15, 20, 12, 3, 10, 6}; //perm = {6,7,5,4,10,1,8,9,2,3};

    cout << "I.1.2_I.3.1_Recursive_p===============================" << endl<<endl;
    for (int i = 0; i < 11; i++) {
        std::cout<<"p(" << i << ") = " << p(i) << std::endl;
    }

    cout<< endl << "II.1.1_RSK============================================" << endl<<endl;
    perm = {6,7,5,4,10,1,8,9,2,3};

    cout<<"Initial permutation:"<<endl;
    for(auto i:perm)cout<<i<<" ";
    cout<<endl;
    auto t = RSK(perm);
    cout << "P:" << endl;
    printJ(get<0>(t), false);
    cout << endl << "Q:" << endl;
    printJ(get<1>(t), false);
    cout << endl;

    cout<< endl << "II.1.2_RSK============================================" << endl<<endl;
    perm = {4,3,7,5,10,9,8,6,1,5};

    cout<<"Initial permutation:"<<endl;
    for(auto i:perm)cout<<i<<" ";
    cout<<endl<<endl;
    t = RSK(perm);
    cout << "P:" << endl;
    printJ(get<0>(t), false);
    cout << endl << "Q:" << endl;
    printJ(get<1>(t), false);
    cout << endl;

    cout<< endl << "II.2.1_rev_RSK========================================" << endl<<endl;

    vector<vector<int>> P = {{1,2,8,10},{3,5,9},{4},{6},{7}};//{{1,2,3,7},{4,6,8},{5,9},{10}};
    vector<vector<int>> Q = {{1,2,3,7},{4,5,9},{6},{8},{10}};
    perm = revRSK(P,Q);
    cout << "P:" << endl;
    printJ(P, false);
    cout << endl << "Q:" << endl;
    printJ(Q, false);
    cout << endl << "Corresponding permutation:" << endl;
    for(auto i:perm)cout<<i<<" ";
    cout<<endl<<endl;

    cout<< endl << "II.2.2_rev_RSK========================================" << endl<<endl;

    P = {{1,2,3,7},{4,6,8},{5,9},{10}};
    Q = {{1,2,5,9},{3,6,10},{4,7},{8}};
    perm = revRSK(P,Q);
    cout << "P:" << endl;
    printJ(P, false);
    cout << endl << "Q:" << endl;
    printJ(Q, false);
    cout << endl << "Corresponding permutation:" << endl;
    for(auto i:perm)cout<<i<<" ";
    cout<<endl<<endl;


    cout<< endl << "II.3_Subsequences=====================================" << endl<<endl;

    perm = {13, 19, 9, 16, 14, 4, 17, 18, 11, 7, 8, 1, 2, 5, 15, 20, 12, 3, 10, 6}; //perm = {6,7,5,4,10,1,8,9,2,3};
    cout<<"Initial permutation:"<<endl;
    for(auto i:perm)cout<<i<<" ";
    cout<<endl<<endl;

    t = RSK(perm);

    cout<<"P:"<<endl;
    printJ(get<0>(t),false);
    cout<<endl<<"Q:"<<endl;
    printJ(get<1>(t),false);
    cout<<endl<<"Subsequences:"<<endl;
    printSS(get<2>(t));


    cout<< endl << "LongestAscendingSS:" << endl;
    auto lss = longestAscendingSS(perm);
    for (auto it:lss)cout << it << " ";

    cout << endl;
    cout<< endl << "LongestDescendingSS:" << endl;
    lss = longestDescendingSS(perm);
    for (auto it:lss)cout << it << " ";
    cout << endl;

    cout<< endl << "III.1.1_Schutzenberger================================" << endl<<endl;

    vector<vector<int>> J = {{1,2,3,9,10,17,19},{4,5,8,1,12},{6,14,16,20},{7},{13},{15},{18}};
    cout << "Young's diagram:" << endl;
    printJ(J, false);
    auto res = schutzenbergerIteration(J,true);
    cout << endl << "After Schutzenberger iteration:" << endl;
    printJ(J, false);
    cout<<endl;
    cout<<"Last moved value:"<<get<2>(res)<<" of col:"<<get<0>(res)<<" row:"<<get<1>(res)<<endl;


    cout<< endl << "III.1.2_Schutzenberger_transform======================" << endl<<endl;

    J = {{1,3,4,5,10,17},{2,8,16,18,20},{6,9},{7,13},{11,14},{12,15},{19}};
    cout << "Young's diagram:" << endl;
    printJ(J, false);
    res = schutzenbergerIteration(J,true);
    cout << endl << "After Schutzenberger iteration:" << endl;
    printJ(J, false);
    cout<<endl;
    cout<<"Last moved value:"<<get<2>(res)<<" of col:"<<get<0>(res)<<" row:"<<get<1>(res)<<endl;

    cout<< endl << "III.1.3_Schutzenberger_transform======================" << endl<<endl;

    J = {{1,2,5,9,11,14,15},{3,4,7,20},{6,8,19},{10,13},{12,17},{16},{18}};
    cout << "Young's diagram:" << endl;
    printJ(J, false);
    res = schutzenbergerIteration(J,true);
    cout << endl << "After Schutzenberger iteration:" << endl;
    printJ(J, false);
    cout<<endl;
    cout<<"Last moved value:"<<get<2>(res)<<" of col:"<<get<0>(res)<<" row:"<<get<1>(res)<<endl;


    cout<< endl << "III.2.1_Schutzenberger_involution=====================" << endl<<endl;

    J = {{1,3,6,11,12},{2,4,9},{5,10},{7},{8},{13},{14},{15}};
    cout << "Young's diagram:" << endl;
    printJ(J, false);

    J = schutzenbergerInvolution(J);
    cout << endl << "After Involution:" << endl;
    printJ(J, false);

    J = schutzenbergerInvolution(J);
    cout << endl << "After second Involution:" << endl;
    printJ(J, false);

    cout<< endl << "III.2.2_Schutzenberger_involution=====================" << endl<<endl;

    J = {{1,5,8,10,12},{2,6,9,13,14},{3,11,15},{4},{7}};
    cout << "Young's diagram:" << endl;
    printJ(J, false);

    J = schutzenbergerInvolution(J);
    cout << endl << "After Involution:" << endl;
    printJ(J, false);

    J = schutzenbergerInvolution(J);
    cout << endl << "After second Involution:" << endl;
    printJ(J, false);


}

void custom(){

    vector<int> perm = {13, 19, 9, 16, 14, 4, 17, 18, 11, 7, 8, 1, 2, 5, 15, 20, 12, 3, 10, 6}; //perm = {6,7,5,4,10,1,8,9,2,3};

    cout << "RSK_and_subsets=======================================" << endl;

    auto t = RSK(perm);
    cout << "P:" << endl;
    printJ(get<0>(t), false);
    cout << endl << "Q:" << endl;
    printJ(get<1>(t), false);
    cout << endl << "SS:" << endl;
    printSS(get<2>(t));
    cout << endl;

    cout << "LongestAscendingSS:" << endl;
    auto lss = longestAscendingSS(perm);
    for (auto it:lss)cout << it << " ";

    cout << endl;
    cout << "LongestDescendingSS:" << endl;
    lss = longestDescendingSS(perm);
    for (auto it:lss)cout << it << " ";
    cout << endl;

    cout << "Reverce RSK:" << endl;
    auto pr = revRSK(get<0>(t), get<1>(t));
    for (auto foo:pr)cout << foo << " ";
    cout << endl;

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

    //cout << "======================================================" << endl;
    cout <<endl<< "Schutzenberger========================================" << endl;

    int iters = 0;

    vector<vector<int>> J1 = {{1,2,3,6},{4,8,10},{5,9},{7}};
    auto J2 = J1;

    cout << endl << "Before Sch:" << endl;
    printJ(J1, false);

    do{
        schutzenbergerIteration(J1,true,true);
        iters++;
    }while(J1!=J2);

    cout << endl << "Iters till loop:"<<iters << endl;


    J2 = schutzenbergerInvolution(J1);
    cout << endl << "After Involution:" << endl;
    printJ(J2, false);

    J2 = schutzenbergerInvolution(J2);
    cout << endl << "After second Involution:" << endl;
    printJ(J2, false);

    //cout << endl <<"Col: "<< get<0>(res)<<" Row:"<<get<1>(res)<<" Val:"<<get<2>(res)<< endl;


    cout << "======================================================" << endl;


    for (int i = 0; i < 11; i++) {
        std::cout<<"p(" << i << ") = " << p(i) << std::endl;
    }
}

int main() {


    tasks();
    return 0;

    vector<int> perm = {13, 19, 9, 16, 14, 4, 17, 18, 11, 7, 8, 1, 2, 5, 15, 20, 12, 3, 10, 6}; //perm = {6,7,5,4,10,1,8,9,2,3};
    auto t = RSK(perm);
    cout << "LongestAscendingSS:" << endl;
    auto lss = longestAscendingSS(perm);
    for (auto it:lss)cout << it << " ";

    cout << endl;
    cout << "LongestDescendingSS:" << endl;
    lss = longestDescendingSS(perm);
    for (auto it:lss)cout << it << " ";
    cout << endl;

    cout << "Reverce RSK:" << endl;
    auto pr = revRSK(get<0>(t), get<1>(t));
    for (auto foo:pr)cout << foo << " ";
    cout << endl;

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

    //cout << "======================================================" << endl;
    cout <<endl<< "Schutzenberger========================================" << endl;

    int iters = 0;

    vector<vector<int>> J1 = {{1,2,3,6},{4,8,10},{5,9},{7}};
    auto J2 = J1;

    cout << endl << "Before Sch:" << endl;
    printJ(J1, false);

    do{
        schutzenbergerIteration(J1,true,true);
        iters++;
    }while(J1!=J2);

    cout << endl << "Iters till loop:"<<iters << endl;


    J2 = schutzenbergerInvolution(J1);
    cout << endl << "After Involution:" << endl;
    printJ(J2, false);

    J2 = schutzenbergerInvolution(J2);
    cout << endl << "After second Involution:" << endl;
    printJ(J2, false);

    //cout << endl <<"Col: "<< get<0>(res)<<" Row:"<<get<1>(res)<<" Val:"<<get<2>(res)<< endl;


    cout << "======================================================" << endl;


    for (int i = 0; i < 11; i++) {
        std::cout<<"p(" << i << ") = " << p(i) << std::endl;
    }
    return 0;
}