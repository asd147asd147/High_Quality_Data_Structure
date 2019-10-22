#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

using namespace std;

ifstream in("2.inp");
ofstream out("2.out");
vector< stack < int > > ans;

void stack_output(stack<int> &a){
    while(!a.empty()){
        out << a.top() << " ";
        a.pop();
    }
}

int NUM_SIZE;
int main(){
    stack <int> temp;
    int num;
    int check = 0;
    in >> NUM_SIZE;
    in >> num;
    temp.push(num);
    ans.push_back(temp);

    for(int i = 0; i < NUM_SIZE-1; i++){
        in >> num;
        check = 0;
        for(int j = 0; j < ans.size(); j++){
            if(ans[j].top() > num){
                ans[j].push(num);
                check = 1;
                break;
            }
            check = 0;
        }
        if(check == 0){
            temp.pop();
            temp.push(num);
            ans.push_back(temp);
        }
    }

    for(int i = 0; i < ans.size(); i++){
        stack_output(ans[i]);
        out << endl;
    }

    return 0;
}
