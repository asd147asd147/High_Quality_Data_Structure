#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

ifstream in("3.inp");
ofstream out("3.out");

queue < int > path;

vector < vector < int > > rumor;
vector < int > temp;
vector < int > check;
int NODE_NUM;
int START;
int FINISH;
int DIS;

int find_index(int num){
    for(int i = 0; i < rumor.size(); i++){
        if(rumor[i][0] == num){
            return i;
        }
    }
    return -1;
}

int main(){
    in >> NODE_NUM >> START >> FINISH;
    int num;
    int t;
    for(int i = 0; i < NODE_NUM; i++){
        in >> num;
        temp.push_back(num);
        while(num != 0){
            in >> num;
            temp.push_back(num);
        }
        rumor.push_back(temp);
        temp.clear();
    }//vector save

    int cnt = 0;
    path.push(START);
    check.push_back(START);
    while(!path.empty()){
        t = path.size();
        for(int i = 0; i < t;i++){
            int index;
            index = find_index(path.front());
            path.pop();
            for(int j = 1; j < rumor[index].size()-1; j++){
                if(find(check.begin(),check.end(),rumor[index][j]) == check.end()){
                    if(rumor[index][j] == FINISH){
                        out << ++DIS << endl;
                        return 0;
                    }
                    path.push(rumor[index][j]);
                    check.push_back(rumor[index][j]);
                }
            }
        }
        DIS++;
    }
    out << -1 << endl;
    return 0;
}
