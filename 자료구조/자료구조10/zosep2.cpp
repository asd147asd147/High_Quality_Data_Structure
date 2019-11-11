#include <iostream>
#include <fstream>
#include <list>

using namespace std;

int main(){

    ifstream in("zosep.inp");
    ofstream out("zosep.out");

    list <int> zos;

    int start,finish;
    in >> start >> finish;
    int NUM = finish-start+1;
    int last = start;
    int stage = 0, flag;
    if(start % 3 == 1){
        for(int i = 1; i <= NUM; ++i){
            if(i % 3 != 1){
                zos.push_back(i);
            }
        }
        stage = 1;
        last -=1;
    }
    else if(start % 3 == 2){
        int j = 2;
        flag = 1;
        for(int i = 2; i <= NUM+1; ++i){
            if(i != j){
                zos.push_back(i);
            }
            else{
                flag ? j+=4 : j+=2;
                flag = !flag;
            }
            if(NUM+1 == j) stage =2;
        }
        stage += 2;
        last -=2;
    }
    else{
        int j = 3;
        flag = 0;
        for(int i = 3; i <= NUM+2; ++i){
            if(i != j){
                zos.push_back(i);
            }
            else{
                flag ? j+=4 : j+=2;
                flag = !flag;
            }
            if(NUM+2 == j) stage = 2;
        }
        stage += 2;
        last -=3;
    }

    list<int>::iterator iter = zos.begin();
    if(stage == 1){
        switch(finish%3){
        case 1:
            ++iter;
        case 2:
            ++iter;
        }
    }
    else if(stage == 2){
        switch(finish%3 + flag){
        case 0:
            ++iter;
        case 1:
            ++iter;
        }
    }
    else if(stage == 4){
        switch(finish%3+flag){
        case 2:
            ++iter;
        case 0:
            ++iter;
        case 1:
            ++iter;
        }
    }
    int temp;
    while(zos.size() != 1){
        temp = (*iter)%3;
        iter = zos.erase(iter);
        if(iter == zos.end()) ++iter;
        switch(temp){
        case 2:
            ++iter;
            if(iter == zos.end()) ++iter;
        case 1:
            ++iter;
            if(iter == zos.end()) ++iter;
        case 0:
            ++iter;
            if(iter == zos.end()) ++iter;
        }
    }
    cout << *zos.begin()+last;

    return 0;
}
