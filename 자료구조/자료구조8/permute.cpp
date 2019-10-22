#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

ifstream in("permute.inp");
ofstream out("permute.out");

int k;
string curr_word, prev_word, next_word;

void input(){
    in >> curr_word >> k;
    prev_word = next_word = curr_word;
}

void output(){
    out << prev_word << endl;
    out << next_word << endl;
}

void find_prev(){
    stack < char > prev_temp;
    vector < char > rest_temp;
    for(int i = prev_word.size()-1; i >= 0; i--){
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
    for(int i = next_word.size()-1; i >= 0; i--){
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
        string temp = prev_word;
        find_prev();
        if(temp == prev_word){
            prev_word = "none";
            break;
        }
    }
    for(int i = 0; i < k; i++){
        string temp = next_word;
        find_next();
        if(temp == next_word){
            next_word = "none";
            break;
        }
    }
}


int main(){

    input();
    solve();
    output();

    return 0;
}
