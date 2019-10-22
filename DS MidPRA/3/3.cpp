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
    int t = 0;
    for(int i = 0; i < NODE_NUM; i++){
        in >> num;
        temp.push_back(num);
        while(num != 0){
            in >> num;
            temp.push_back(num);
        }
        rumor.push_back(temp);
        temp.clear();
    }

    path.push(START);
    while(path.front() != FINISH){
        int i;
        i = find_index(path.front());
        check.push_back(path.front());
        path.pop();
        for(int j = 1; j < rumor[i].size()-1;j++){
            auto iter = find(check.begin(),check.end(),rumor[i][j]);
            if(iter == check.end()){
                path.push(rumor[i][j]);
            }
        }
    }
    cout << DIS<<endl;
    return 0;
}
