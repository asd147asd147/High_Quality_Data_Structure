#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

ifstream in("virus.inp");
ofstream out("virus.out");

int COL_N;
int ROW_M;
int VIRUS_S;
int VIRUS_NUM = 0;
int MAX_SIZE = 0;

vector<vector<int>> VIRUS_DATA;

void input(){
    in >> COL_N >> ROW_M >> VIRUS_S;
    for(int i = 0; i < ROW_M; ++i){
        vector<int> virus_temp;
        char data;
        for(int j = 0; j < COL_N; ++j){
            in >> data;
            data == '#' ? virus_temp.push_back(1) : virus_temp.push_back(0);
        }
        VIRUS_DATA.push_back(virus_temp);
    }
}

void find_virus(){
    for(int i = 0; i < ROW_M; ++i){
        for(int j = 0; j < COL_N; ++j){
            if(VIRUS_DATA[i][j] == 1){
                queue< tuple<int, int> > check_virus;
                int check_virus_size = 1;
                check_virus.push(make_tuple(i,j));
                VIRUS_DATA[i][j] = 0;
                while(!check_virus.empty()){
                    int temp_i = get<0>(check_virus.front());
                    int temp_j = get<1>(check_virus.front());
                    check_virus.pop();
                    if(temp_j+1 < COL_N && VIRUS_DATA[temp_i][temp_j+1] == 1){
                        VIRUS_DATA[temp_i][temp_j+1] = 0;
                        check_virus.push(make_tuple(temp_i,temp_j+1));
                        ++check_virus_size;
                    }
                    if(temp_j-1 >= 0 && VIRUS_DATA[temp_i][temp_j-1] == 1){
                        VIRUS_DATA[temp_i][temp_j-1] = 0;
                        check_virus.push(make_tuple(temp_i,temp_j-1));
                        ++check_virus_size;
                    }
                    if(temp_i-1 >= 0 && VIRUS_DATA[temp_i-1][temp_j] == 1){
                        VIRUS_DATA[temp_i-1][temp_j] = 0;
                        check_virus.push(make_tuple(temp_i-1,temp_j));
                        ++check_virus_size;
                    }
                    if(temp_i+1 < ROW_M && VIRUS_DATA[temp_i+1][temp_j] == 1){
                        VIRUS_DATA[temp_i+1][temp_j] = 0;
                        check_virus.push(make_tuple(temp_i+1,temp_j));
                        ++check_virus_size;
                    }
                }
                if(check_virus_size >= VIRUS_S){
                    ++VIRUS_NUM;
                    if(MAX_SIZE < check_virus_size)
                        MAX_SIZE = check_virus_size;
                }
            }
        }
    }
}

void solve(){
    find_virus();
}

void output(){
    out << VIRUS_NUM << " " << MAX_SIZE;
}

int main(){
    input();
    solve();
    output();
    return 0;
}
