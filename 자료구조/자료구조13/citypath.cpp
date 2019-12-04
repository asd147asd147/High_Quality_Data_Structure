#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 99999

using namespace std;

ifstream in("1.inp");
ofstream out("citypath.out");

int NODENUM;

vector<vector<int>> NODEDATA;
vector<vector<int>> WEIGHT;

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
    for(int i = 0; i < NODENUM; ++i){
        vector <int> tempdata;
        for(int j = 0; j < NODENUM; ++j){
            tempdata.push_back(INF);
        }
        WEIGHT.push_back(tempdata);
    }
}

void input_weight(){
    for(int i = 0; i < NODENUM; ++i){
        for(int j = 0; j < NODEDATA[i].size(); ++j){
            if(i == NODEDATA[i][j]-1){
                WEIGHT[i][i] = 0;
            }
            else{
                WEIGHT[i][NODEDATA[i][j]-1] = NODEDATA[NODEDATA[i][j]-1].size()-2;
            }
        }
    }
}

void solve(){
    input_weight();
}

void output(){
    for(auto s : WEIGHT){
        for(auto t : s){
            cout << t;
        }
        cout <<endl;
    }
}

int main(){
    input();
    solve();
    output();
    return 0;
}
