#include <bits/stdc++.h>
#define NC node->ptr[0]->data == node->ptr[1]->data && node->ptr[2]->data == node->ptr[3]->data && node->ptr[0]->data == node->ptr[2]->data
using namespace std;

const int size = 4;
typedef struct tree{
    int data;
    tree* ptr[size];
} TREE;

ifstream in("1.inp");
ofstream out("quad.out");

vector<string> str;
TREE* root = new TREE;

int quad_size;
int depth;

void input(){
    string s1;
    in >> quad_size;
    depth = quad_size+1;
    for(int i = 0; i < 1<<quad_size; i++){
        in >> s1;
        str.push_back(s1);
    }
}

void make_leaf(TREE* node, int d){
    if(d != 1){
        node->data = 2;
        for(int i = 0; i < size; i++){
            node->ptr[i] = new TREE;
        }
        for(int i = 0; i < size; i++){
            make_leaf(node->ptr[i], d-1);
        }
    }
    else{
        node->data = 2;
        for(int i = 0; i < size; i++){
            node->ptr[i] = NULL;
        }
    }
}

int s_even = 0, s_odd = 1;
int even_i = 0, odd_i = 0;

void push_tree(TREE* node, int d){
    char c;
    string s;
    int s_i;
    if(d != 1){
        for(int i = 0; i < size; i++){
            if(i <= 1){
                s = str[s_even];
                s_i = even_i;
            }
            else{
                s = str[s_odd];
                s_i = odd_i;
            }
            push_tree(node->ptr[i],d-1);
        }
    }
    else{
        if(s[s_i] == '_'){
            node->data = 0;
        }
        else{
            node->data = 1;
        }
    }
}

void solve(){
    make_leaf(root, depth);
    push_tree(root, depth);
}

int main() {
    input();
    solve();
    return 0;
}

