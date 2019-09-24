#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

ifstream in("polymult.inp");
ofstream out("polymult.out");
vector < tuple < int, int > > fx;

void polyadd(int num_c, int num_e) {
    bool check = 1;
    for(int i = 0; i < fx.size(); i++) {
        if(get<0>(fx[i])==num_e) {
            get<1>(fx[i]) += num_c;
            if(get<1>(fx[i])==0) {
                fx.erase(fx.begin()+i);
            }
            check = !check;
            break;
        }
    }
    if(check) {
        fx.push_back(make_tuple(num_e,num_c));
    }
}

void polymult(int num_c, int num_e){
    vector < tuple <int, int> > temp_fx;
    int temp_num_e;
    int temp_num_c;
    for(int i = 0; i<fx.size();i++){
        temp_num_e = num_e+get<0>(fx[i]);
        temp_num_c = num_c*get<1>(fx[i]);
        if(temp_num_c){
            temp_fx.push_back(make_tuple(temp_num_e,temp_num_c));
        }
    }
    fx.clear();
    fx = temp_fx;

}

void solve(){
    int num_fx;
    int num_c, num_e;
    int num_term;

    in >> num_fx;

    for(int i = 0; i<num_fx; i++){
        in >> num_term;
        for(int j = 0; j<num_term; j++){
            in >> num_c >> num_e;
            if(fx.size()){
                polymult(num_c,num_e);
            }
            else{
                polyadd(num_c,num_e);
            }
            sort(fx.begin(),fx.end(),greater<tuple<int,int>>());
        }
    }
}

void output(){
    out << fx.size() << endl;
    if(fx.size()){
        for(int i = 0; i < fx.size(); i++){
            out << get<1>(fx[i]) << " " << get<0>(fx[i]) << endl;
        }
    }
    else{
        out << "0 0";
    }
}

int main() {

    solve();
    output();


    //input();
    //solve();
    //output();
    //ending();

    return 0;
}
