#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

ifstream in("1.inp");
ofstream out("citypath.out");

int NODENUM;

vector<vector<int>> NODEDATA;

void input(){
    in >> NODENUM;

    int temp;
    for(int i = 0; i < NODENUM; ++i){
        vector <int> tempdata;
        in >> temp;
        while(temp != 0){
            tempdata.push_back(temp);
            in >> temp;
        }
        NODEDATA.push_back(tempdata);
    }
}


void solve(){

}

void output(){
    for(auto s : NODEDATA){
        for(auto t : s){
            cout << t;
        }
        cout <<endl;
    }
}

int main(){
    input();
    solve();
    //output();
    return 0;
}
