#include <bits/stdc++.h>
using namespace std;

const int size = 4;
typedef struct tree{
    int data;
    tree* ptr[size];
} TREE;

ifstream in("test.inp");
ofstream out("quad.out");

vector<vector<int>> code;
vector<int>sort_code;

TREE* root = new TREE;

int quad_size;
int depth;

void input(){
    char c;
    in >> quad_size;
    depth = quad_size+1;
    for(int i = 0; i < 1<<quad_size; i++){
        vector<int> temp;
        for(int j = 0; j < 1<<quad_size; j++){
            in >> c;
            if(c == '#')
                temp.push_back(1);
            else
                temp.push_back(0);
        }
        code.push_back(temp);
    }
}

void sort_node(){
    int line1 = 0, line2 = 1;
    for(int i = 0;i < 1 << quad_size-1; i++){
        for(int j = 0;j < 1 << quad_size;j+=2){
            sort_code.push_back(code[line1][j]);
            sort_code.push_back(code[line1][j+1]);
            sort_code.push_back(code[line2][j]);
            sort_code.push_back(code[line2][j+1]);
        }
        line1+=2;
        line2+=2;
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

int node_index = 0;
void push_node(TREE* node){
    for(int i = 0; i < size; i++){
        if(node->ptr[i] != NULL){
            push_node(node->ptr[i]);
        }
        else{
            node->data = sort_code[node_index];
            node_index++;
            break;
        }
    }

}

int reduce_tree(TREE* node){
    if(node->data != 2){
        return node->data;
    }
    else if(reduce_tree(node->ptr[0]) == reduce_tree(node->ptr[1]) && reduce_tree(node->ptr[2]) == reduce_tree(node->ptr[3]) && node->ptr[0]->data == node->ptr[2]->data){
        node->data = node->ptr[0]->data;
        for(int i = 0; i < size; i++)
            node->ptr[i] = NULL;
    }
}

void solve(){
    make_leaf(root, depth);
    sort_node();
    push_node(root);
    //reduce_tree(root);
}

void print_tree(TREE* node){
    out << node->data << " ";
    if(node->data == 2){
        out << "(" << " ";
        print_tree(node->ptr[1]);
        print_tree(node->ptr[0]);
        print_tree(node->ptr[2]);
        print_tree(node->ptr[3]);
        out << ")" << " ";
    }
}

void output(){
    print_tree(root);
}

int main() {
    input();
    solve();
    output();
    return 0;
}

