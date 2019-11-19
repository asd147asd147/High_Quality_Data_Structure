#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

ifstream in("test.inp");
ofstream out("bts.out");

typedef struct bts {
    string key = "\0";
    int depth;
    bts* leftnode = NULL;
    bts* rightnode = NULL;
} BTS;

int CMD_N;

BTS* root = new BTS;

void input(){
    in >> CMD_N;
}

void push_leaf(BTS* node, string d, int depth){
    if(node->key == "\0"){
        node->depth = depth+1;
        node->key = d;
    }
    else if(node->key > d){
        if(node->leftnode == NULL){
            node->leftnode = new bts;
            push_leaf(node->leftnode,d,depth+1);
        }
        else{
            push_leaf(node->leftnode,d,depth+1);
        }
    }
    else{
        if(node->rightnode == NULL){
            node->rightnode = new bts;
            push_leaf(node->rightnode,d,depth+1);
        }
        else{
            push_leaf(node->rightnode,d,depth+1);
        }
    }
}

int node_size(BTS* node){
    int n_s=1;
    if(node->leftnode == NULL && node->rightnode == NULL){
        return n_s;
    }
    else {
        if(node->leftnode != NULL){
            n_s += node_size(node->leftnode);
        }
        if(node->rightnode != NULL){
            n_s += node_size(node->rightnode);
        }
    }
    return n_s;
}
vector < string > str_leaf;
void print_leaf(BTS* node){
    if(node_size(node) == 1)
        str_leaf.push_back(node->key);
    else {
        if(node->leftnode != NULL){
            print_leaf(node->leftnode);
        }
        if(node->rightnode != NULL){
            print_leaf(node->rightnode);
        }
    }
}

vector < string > str_depth;
void print_depth(BTS* node, int d){
    if(node->depth == d){
        str_depth.push_back(node->key);
    }
    else{
        if(node->leftnode != NULL){
            print_depth(node->leftnode,d);
        }
        if(node->rightnode != NULL){
            print_depth(node->rightnode,d);
        }
    }
}

BTS* find_node(BTS* node, string s){
    BTS* temp;
    if(node->key == s){
        return node;
    }
    else{
        if(node->key > s){
            if(node->leftnode != NULL){
                temp = find_node(node->leftnode,s);
                return temp ? temp : NULL;
            }
            else
                return NULL;
        }
        else{
            if(node->rightnode != NULL){
                temp = find_node(node->rightnode,s);
                return temp ? temp : NULL;
            }
            else
                return NULL;
        }
    }
}

BTS* find_max_node(BTS* node){
    if(node->rightnode != NULL)
        return find_max_node(node->rightnode);
    else
        return node;
}

BTS* find_min_node(BTS* node){
    if(node->leftnode != NULL)
        return find_min_node(node->leftnode);
    else
        return node;
}

void find_node_address(BTS* start_node, BTS* node){
    if(start_node->leftnode != NULL){
        if(start_node->leftnode == node){
            start_node->leftnode = NULL;
        }
        else{
            find_node_address(start_node->leftnode, node);
        }
    }
    if(start_node->rightnode != NULL){
        if(start_node->rightnode == node){
            start_node->rightnode = NULL;
        }
        else{
            find_node_address(start_node->rightnode, node);
        }
    }
}

BTS* erase_node(BTS* node){
    if(node->leftnode != NULL){
        BTS* max_node = find_max_node(node->leftnode);
        string temp_string = max_node->key;
        erase_node(max_node);
        node->key = temp_string;
        return NULL;
    }
    if(node->rightnode != NULL){
        BTS* min_node = find_min_node(node->rightnode);
        string temp_string = min_node->key;
        erase_node(min_node);
        node->key = temp_string;
        return NULL;
    }
    else{
        if(root == node){
            root->key = '\0';
            root->leftnode = NULL;
            root->rightnode = NULL;
        }
        else{
            find_node_address(root,node);
            delete node;
            return NULL;
        }
    }
}

void solve(){
    string cmd;
    for(int i = 0; i < CMD_N; i++){
        string data;
        in >> cmd;
        if(cmd == "+"){
            in >> data;
            push_leaf(root,data,0);
        }
        else if(cmd == "-"){
            in >> data;
            BTS* f_node = find_node(root,data);
            if(f_node != NULL)
                erase_node(f_node);
        }
        else if(cmd == "leaf"){
            str_leaf.clear();
            print_leaf(root);
            for(auto s : str_leaf)
                out << s << " ";
            out << endl;
        }
        else if(cmd == "depth"){
            int k;
            in >> k;
            str_depth.clear();
            print_depth(root,k);
            if(str_depth.empty())
                out << "NO";
            else{
                sort(str_depth.begin(),str_depth.end());
                for(auto s : str_depth)
                    out << s << " ";
            }

            out << endl;
        }
    }
}

int main(){
    input();
    solve();
    return 0;
}
