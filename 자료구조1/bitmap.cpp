#include <iostream>
#include <fstream>
#include <string>

#define ARRAY_MAX 64

using namespace std;

int main(){
    ifstream in("2.inp");
    ofstream out("2.out");
    long long savell;

    long long temp[ARRAY_MAX][ARRAY_MAX]={0,};

    for(int i = 0; i < ARRAY_MAX; i++){
        in >> savell;
        for(int j = 0; j < ARRAY_MAX; j++){
            temp[i][ARRAY_MAX-1-j] = savell & 1;
            savell >>= 1 ;
        }
    }

    for(int i = 0; i < ARRAY_MAX; i++){
            savell = 0;
        for(int j = 0; j < ARRAY_MAX; j++){
            savell <<= 1 ;
            savell += temp[j][i] & 1;
        }
            out << savell << endl;
    }
    in.close();
    out.close();
    return 0;
}
