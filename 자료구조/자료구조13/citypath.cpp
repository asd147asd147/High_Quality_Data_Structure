#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 99999

using namespace std;

ifstream in("citypath.inp");
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

int find_short_path(int start){
    vector<int> dist(NODENUM,INF);
    dist[start] = 0;
    while(find(dist.begin(),dist.end(),INF) != dist.end())
        for(int i = 0; i < NODENUM; ++i){
            if(start == i){
                for(int j = 1; j < NODEDATA[i].size(); ++j){
                    dist[NODEDATA[i][j]-1] = 1;
                }
            }
            else{
                for(int j = 1; j < NODEDATA[i].size(); ++j){
                    if(dist[i]+NODEDATA[i].size()-1 < dist[NODEDATA[i][j]-1]){
                        dist[NODEDATA[i][j]-1] = dist[i]+NODEDATA[i].size()-1;
                    }
                }
            }
        }
    for(int i = 0; i < NODENUM; ++i){
        if(start == i){
            for(int j = 1; j < NODEDATA[i].size(); ++j){
                dist[NODEDATA[i][j]-1] = 1;
            }
        }
        else{
            for(int j = 1; j < NODEDATA[i].size(); ++j){
                if(dist[i]+NODEDATA[i].size()-1 < dist[NODEDATA[i][j]-1]){
                    dist[NODEDATA[i][j]-1] = dist[i]+NODEDATA[i].size()-1;
                }
            }
        }
    }

    sort(dist.begin(),dist.end());
    return dist[NODENUM-1];
}

vector<int> D;
void solve(){
    input_weight();
    for(int i = 0; i < NODENUM; ++i){
        D.push_back(find_short_path(i));
    }
    sort(D.begin(),D.end());
}

void output(){
    out << D[NODENUM-1];
}

int main(){
    input();
    solve();
    output();
    return 0;
}
