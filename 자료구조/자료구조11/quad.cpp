#include <bits/stdc++.h>
using namespace std;

const int size = 4;
struct tree{   // �� ��忡�� �ڽ� ����� �ִ밳���� 6��.
    int data;
    tree* ptr[size];
};

ifstream in("1.inp");
ofstream out("quad.out");

vector <char> data;

int quad_size;

void input(){
    in >> quad_size;
}

void solve(){
    char d;
    for(int i =0; i < quad_size<<2*quad_size;i++){
        in >> d;
        data.push_back(d);
    }
}

int main() {
    input();
    solve();
    for(auto s : data)
        cout << s;
    return 0;
}

