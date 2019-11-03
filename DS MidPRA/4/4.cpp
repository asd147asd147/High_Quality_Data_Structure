#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

ifstream in("4.inp");
ofstream out("4.out");

vector < int > vec;
stack < int > temp;

int N_SIZE;
int N_SWAP;

int main(){
    int swap_f, swap_e;
    in >> N_SIZE >> N_SWAP;
    for(int i = 0; i <= N_SIZE; i++){
        vec.push_back(i);
    }
    for(int i = 0; i < N_SWAP; i++){
        in >> swap_f >> swap_e;
        for(int j = swap_f; j <= swap_e; j++){
            temp.push(vec[j]);
        }
        for(int j = swap_f; j <= swap_e; j++){
            vec[j] = (-1)*temp.top();
            temp.pop();
        }
    }
    for(auto s : vec){
        out << s << " ";
    }
    return 0;
}
