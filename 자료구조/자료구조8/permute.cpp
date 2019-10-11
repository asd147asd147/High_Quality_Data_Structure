#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

ifstream in("1.inp");
ofstream out("permute.out");

int k;
char curr_word[16];
char prev_word[16];
char next_word[16];

void input();
void output();
int length();
void find_prev();
void find_next();
void solve();

void input(){
    in >> curr_word >> k;
    for(int i = 0; i < curr_word[i] != 0; i++){
        prev_word[i] = curr_word[i];
        next_word[i] = curr_word[i];
    }
}

void output(){
    out << prev_word << endl;
    out << next_word << endl;
}

int length(char word[]){
    int i;
    for(i = 0; word[i] != 0; i++);
    return i;
}

void find_prev(){
    stack < char > prev_temp;
    vector < char > rest_temp;
    for(int i = length(prev_word)-1; i >= 0; i--){
        if(prev_temp.empty()){
            prev_temp.push(prev_word[i]);
            rest_temp.push_back(prev_word[i]);
        }
        else if(prev_temp.top() < prev_word[i]){
            rest_temp.push_back(prev_word[i]);
            sort(rest_temp.begin(),rest_temp.end(),[](const char a, const char b) {return a > b;});
            for(int j = 0; j < rest_temp.size(); j++){
                if(rest_temp[j] < prev_word[i]){
                    prev_word[i] = rest_temp[j];
                    rest_temp.erase(rest_temp.begin()+j);
                    break;
                }
            }
            for(int k = 0; k < rest_temp.size(); k++){
                prev_word[i+1+k] = rest_temp[k];
            }
            return ;
        }
        else{
            prev_temp.push(prev_word[i]);
            rest_temp.push_back(prev_word[i]);
        }
    }
}

void find_next(){
    stack < char > next_temp;
    vector < char > rest_temp;
    for(int i = length(next_word)-1; i >= 0; i--){
        if(next_temp.empty()){
            next_temp.push(next_word[i]);
            rest_temp.push_back(next_word[i]);
        }
        else if(next_temp.top() > next_word[i]){
            rest_temp.push_back(next_word[i]);
            sort(rest_temp.begin(),rest_temp.end());
            for(int j = 0; j < rest_temp.size(); j++){
                if(rest_temp[j] > next_word[i]){
                    next_word[i] = rest_temp[j];
                    rest_temp.erase(rest_temp.begin()+j);
                    break;
                }
            }
            for(int k = 0; k < rest_temp.size(); k++){
                next_word[i+1+k] = rest_temp[k];
            }
            return ;
        }
        else{
            next_temp.push(next_word[i]);
            rest_temp.push_back(next_word[i]);
        }
    }
}

void solve(){
    for(int i = 0; i < k; i++){
        find_prev();
    }
    for(int i = 0; i < k; i++){
        find_next();
    }
}

int main(){

    input();
    solve();
    output();

    return 0;
}
