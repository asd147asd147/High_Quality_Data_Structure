#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
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
}

void make_weight(){
    for(int i = 0; i < NODENUM; ++i){
        vector <int> tempdata(NODENUM,INF);
        for(int j = 0; j < NODEDATA[i].size();++j){
            i == NODEDATA[i][j]-1 ? tempdata[i] = 0 : tempdata[NODEDATA[i][j]-1] = NODEDATA[NODEDATA[i][j]-1].size()-2;
        }
        WEIGHT.push_back(tempdata);
    }
}

int found_short_path(int start){
    vector<int> dist(NODENUM,INF);
    vector<int> temp(NODENUM,INF);
    dist[start] = 0;
    temp[start] = 0;
    for(int k = 0; k < 20; ++k){
        for(int i = 0; i < NODENUM; ++i){
            for(int j = 0; j < NODEDATA[(start + i)%NODENUM].size(); ++j){
                if(dist[(start + i)%NODENUM] + WEIGHT[(start + i)%NODENUM][NODEDATA[(start + i)%NODENUM][j]-1] + 1 < dist[NODEDATA[(start + i)%NODENUM][j]-1]){
                    dist[NODEDATA[(start + i)%NODENUM][j]-1] = dist[(start + i)%NODENUM] + WEIGHT[(start + i)%NODENUM][NODEDATA[(start + i)%NODENUM][j]-1] + 1;
                    temp[NODEDATA[(start + i)%NODENUM][j]-1] = WEIGHT[(start + i)%NODENUM][NODEDATA[(start + i)%NODENUM][j]-1];
                }

            }
        }
    }

    for(int i = 0; i < NODENUM; ++i)
        dist[i] -= temp[i];
    sort(dist.begin(),dist.end());
    return dist[NODENUM-1];
}

vector <int> D;
void solve(){
    make_weight();
    for(int i = 0; i < NODENUM; ++i)
        D.push_back(found_short_path(i));
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
