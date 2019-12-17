#include <iostream>
#include <fstream>
#include <forward_list>

using namespace std;

ifstream in("test.inp");
ofstream out("zosep.out");

forward_list <int> zos;

int start, finish;
int temp;

void input(){
    in >> start >> finish;
}

void output(){
    out << temp;
}

void make_list(int s, int f){
    auto iter = zos.before_begin();
    for(int i = s; i <= f; ++i){
        iter = zos.insert_after(iter, i);
    }
}

void del(){
    for(auto i = zos.before_begin(); !zos.empty();){
        temp = *i+1;
        cout << "t"<<*i <<endl;
        i=zos.erase_after(i);
        for(auto s : zos)
            cout << s << " ";
        cout <<"temp " << temp%3 <<endl;
        cout << "e" <<*i <<endl;
        if(i == zos.end()){
            i = zos.before_begin();
        }
        switch(temp%3){
        case 2:
            ++i;
            if(i == zos.end()){
                i = zos.before_begin();
            }
        case 1:
            ++i;
            if(i == zos.end()){
                i = zos.before_begin();
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
