#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>




using namespace std;

ifstream in("5.inp");
ofstream out("5.out");
vector <int> seta { 4, 11, 2, 5, 5, 6, 30, 7, 50} ;
vector <int> setb { 44, 555, 600 } ;
vector <int> temp;
int main(){

    for(auto i = seta.begin(); i != seta.end(); i++){
        if(find(setb.begin(),setb.end(),*i) == setb.end()){
            temp.push_back(*i);
        }
    }
    seta.clear();
    seta = temp;

    for(auto it = seta.begin() ; it != seta.end() ; it++) {
        printf("%d ", *it ) ;
    }
    return 0;
}
