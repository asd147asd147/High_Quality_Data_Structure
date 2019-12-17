#include <iostream>
#include <fstream>
#include <list>
#include <queue>
#include <string>

using namespace std;

ifstream in("shuffle.inp");
ofstream out("shuffle.out");

list<int> DECK;
int CARD_NUM;
int SHUFFLE_NUM;

void input(){
    in >> CARD_NUM >> SHUFFLE_NUM;
}

void output(){
    auto i = DECK.begin();
    for(int k = 0; k < CARD_NUM/2-1; k++){
        i++;
    }
    out << *(DECK.begin()) << " " << *i << " " <<*(--DECK.end());
}

void make_deck(){
    for(int i = 1; i <= CARD_NUM; i++){
        DECK.push_back(i);
    }
}

void shuffle(){
    queue<int> temp;
    auto i = DECK.begin();
    for(int k = 0; k != CARD_NUM/2; k++){
        i++;
    }

    while(i!=DECK.end()){
        temp.push(*i);
        i = DECK.erase(i);
    }

    i = ++DECK.begin();
    while(!temp.empty()){
        DECK.insert(i,temp.front());
        i++;
        temp.pop();
    }
}

void cut(int i, int j){
    auto cut_start = DECK.begin();
    auto cut_end = DECK.begin();
    list<int> temp;
    for(int k = 0; k < i-1; k++){
        cut_start++;
    }
    for(int k = 0; k < j; k++){
        cut_end++;
    }
    DECK.splice(DECK.end(),DECK,cut_start,cut_end);
}

void solve(){
    string s;
    for(int i = 0; i < SHUFFLE_NUM; i++){
        int cut_s, cut_e;
        in >> s;
        if(s == "Shuffle"){
            shuffle();
        }
        else{
            in >> cut_s >> cut_e;
            cut(cut_s,cut_e);
        }
    }

}

int main(){
    input();
    make_deck();
    solve();
    output();

    return 0;
}
