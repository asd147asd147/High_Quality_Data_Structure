#include <iostream>

using namespace std;


template <typename T>
class BTS{
public:
    T data = 0;
    BTS(){
    }
    BTS(T d){
        data = d;
    }
    BTS(T d, BTS* l, BTS* r){
        data = d;
        leftnode = l;
        rightnode = r;
    }

    void insert_node(T d){
        if(data == 0)
            data = d;
        else{
            if(data > d){
                if(leftnode == nullptr){
                    leftnode = new BTS(d);
                }
                else{
                    leftnode->insert_node(d);
                }
            }
            else{
                if(rightnode == nullptr){
                    rightnode = new BTS(d);
                }
                else{
                    rightnode->insert_node(d);
                }
            }
        }
    }

    T print_node(){
        return data;
    }

    int node_size(){
        int n_s = 1;
        if(leftnode != nullptr){
            n_s += leftnode->node_size();
        }
        if(rightnode != nullptr){
            n_s += rightnode->node_size();
        }
        return n_s;
    }

    void print_leaf(){
        if(node_size() == 1){
            cout << data << " ";
            return;
        }
        else{
            if(leftnode != nullptr){
                leftnode->print_leaf();
            }
            if(rightnode != nullptr){
                rightnode->print_leaf();
            }
            return;
        }
    }

    int node_depth(){
        int left_depth = 0;
        int right_depth = 0;
        if(leftnode == nullptr && rightnode == nullptr)
            return 1;
        else{
            if(leftnode != nullptr){
                left_depth = leftnode->node_depth();
            }
            if(rightnode != nullptr){
                right_depth = rightnode->node_depth();
            }
            return left_depth > right_depth ? left_depth+1 : right_depth+1;
        }
    }
    BTS* leftnode = nullptr;
    BTS* rightnode = nullptr;

};


int main(){
    BTS<int> test;
    test.insert_node(2);
    test.insert_node(1);
    test.insert_node(3);
    test.insert_node(5);

    cout << test.node_size();

    return 0;
}
