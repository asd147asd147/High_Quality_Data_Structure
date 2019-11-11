#include <iostream>
#include <fstream>
#include <list>

using namespace std;

ifstream in("zosep.inp");
ofstream out("zosep.out");

list <int> zos;

int start, finish;

void input(){
    in >> start >> finish;
}

void output(){
    out << *zos.begin();
}

void make_list(int s, int f){
    for(int i = s; i <= f; ++i){
        zos.push_back(i);
    }
}

void del(){
    int temp;
    for(auto i = zos.begin(); zos.size() != 1;){
        temp = *i;
        i=zos.erase(i);
        if(i == zos.end()){
            ++i;
        }
        switch(temp%3){
        case 2:
            ++i;
            if(i == zos.end()){
                ++i;
            }
        case 1:
            ++i;
            if(i == zos.end()){
                ++i;
            }
        case 0:
            ++i;
            if(i == zos.end()){
                ++i;
            }
        }
    }
}

void solve(){
    make_list(start,finish);
    del();

}

int main(){
    input();
    solve();
    output();

    return 0;
}
