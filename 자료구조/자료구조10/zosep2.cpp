#include <iostream>
#include <fstream>
#include <list>

using namespace std;

struct data{
    int num;
    int mod;
};
int main(){

    ifstream in("3.inp");
    ofstream out("zosep.out");

    list <data> zos;

    int start,finish;
    int NUM;
    data temp;
    in >> start >> finish;

    NUM = finish - start;
    temp.num = start;
    temp.mod = temp.num%3;
    zos.push_back(temp);
    for(int i = 1; i <= NUM; ++i){
        ++temp.num;
        ++temp.mod;
        if(temp.mod == 3){
            temp.mod = 0;
        }
        zos.push_back(temp);
    }

    int cnt = 0;
    int jum;
    for(auto i = zos.begin(); cnt != NUM; ++cnt){
        jum = i->mod+1;
        i = zos.erase(i);
        switch (jum){
        case 3:
            if(i == zos.end()){
                ++i;
            }
            ++i;
            if(i == zos.end()){
                ++i;
            }
        case 2:
            if(i == zos.end()){
                ++i;
            }
            ++i;
            if(i == zos.end()){
                ++i;
            }
        case 1:
            if(i == zos.end()){
                ++i;
            }
            ++i;
            if(i == zos.end()){
                ++i;
            }
        }
    }
    out << (*zos.begin()).num;

    return 0;
}
