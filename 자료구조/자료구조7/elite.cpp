#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <stack>
#include <algorithm>

using namespace std;

ifstream in("elite.inp");
ofstream out("elite.out");
vector < tuple <int, int, int> > LAB;
vector <int> ELITE;
int LAB_NUM = 0;

bool comp(const tuple<int, int, int>& a, const tuple<int, int, int>& b){
    if(get<0>(a) == get<0>(b)){
        return (get<1>(a) > get<1>(b));
    }
    return (get<0>(a) < get<0>(b));
}

void input() {
    int code, hours;
    int num = 1;
    in >> LAB_NUM;
    for(int i = 0; i < LAB_NUM; i++){
        in >> code >> hours;
        LAB.push_back(make_tuple(code,hours,num+i));
    }
}

void sort_vec(){
    sort(LAB.begin(),LAB.end(),comp);
}

void dist(){
    stack <int> elite;
    int i = 0;
    while(i < LAB_NUM){
        if(!elite.empty() && (get<1>(LAB[elite.top()]) < (get<1>(LAB[i])))){
            if( (get<0>(LAB[elite.top()]) < (get<0>(LAB[i]))) ){
                elite.pop();
            }
            else{
                elite.push(i);
                i++;
            }
        }
        else{
            elite.push(i);
            i++;
        }
    }
    while(!elite.empty()){
        ELITE.push_back(get<2>(LAB[elite.top()]));
        elite.pop();
    }
}

void sort_elite(){
    sort(ELITE.begin(),ELITE.end());
}

void solve(){
    sort_vec();
    dist();
    sort_elite();
}

void output(){
    for(int i = 0; i < ELITE.size(); i++){
        out << ELITE[i] << endl;
    }
}

int main(){

    input();
    solve();
    output();

    return 0;
}
