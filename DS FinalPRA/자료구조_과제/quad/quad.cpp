#include <bits/stdc++.h>
using namespace std;

ifstream in("quad.inp");
ofstream out("quad.out");

typedef struct tree{
    int key;
    tree* ptr[4];
} TREE;

vector<vector<int>> data;

vector<int> sort_data;

TREE* root = new TREE;

int n;
int line = 1;

void input(){
    in>>n;
    line = line << n;
    for(int i = 0; i < line; i++){
        vector<int> temp;
        for(int j = 0; j < line; j++){
            char c;
            in >> c;
            if(c == '#') temp.push_back(1);
            else temp.push_back(0);
        }
        data.push_back(temp);
    }
}

void data_sort(int start_x, int start_y, int size){
    if(size == 1){
        sort_data.push_back(data[start_x][start_y]);
    }
    else{
        data_sort(start_x,start_y,size/2);
        data_sort(start_x,start_y-(size/2),size/2);
        data_sort(start_x+(size/2),start_y-(size/2),size/2);
        data_sort(start_x+(size/2),start_y,size/2);
    }
}

int leaf_index = 0;
void make_tree(TREE* node, int size){
    if(size == 1){
        node->key = sort_data[leaf_index];
        for(int i = 0; i < 4; i++)
            node->ptr[i] = NULL;
        leaf_index++;
    }
    else{
        node->key = 2;
        for(int i = 0; i < 4; i++)
            node->ptr[i] = new TREE;
        for(int i = 0; i < 4; i++)
            make_tree(node->ptr[i],size/2);
    }
}

int reduce_tree(TREE* node){
    if(node->ptr[0] != NULL){
        int n0,n1,n2,n3;
        n0 = reduce_tree(node->ptr[0]);
        n1 = reduce_tree(node->ptr[1]);
        n2 = reduce_tree(node->ptr[2]);
        n3 = reduce_tree(node->ptr[3]);
        if(n0 == n1 && n2 == n3 && n0 == n2){
            if(n0 != 2){
                node->key = n0;
                for(int i = 0; i < 4; i++)
                    node->ptr[i] = NULL;
                return n0;
            }
            else{
                return 2;
            }
        }
        return 2;
    }
    else{
        return node->key;
    }
}

void print_tree(TREE* node){
    if(node->ptr[0] == NULL){
        out << node->key << " ";
    }
    else{
        out << node->key << " ( ";
        for(int i = 0; i < 4; i++)
            print_tree(node->ptr[i]);
        out << ") ";
    }
}

void solve(){
    data_sort(0,line-1,line);
    make_tree(root,line);
    reduce_tree(root);
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

