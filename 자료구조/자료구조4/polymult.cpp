#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

ifstream in("polymult.inp");
ofstream out("polymult.out");
vector < tuple < int, int > > fx;
vector < tuple <int, int> > temp_fx;

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

void polyadd(int num_c, int num_e, vector<tuple<int,int>>& fx_Add) { // 이 코드는 3번 제가 제출한 polyadd 코드를 활용하였습니다.
    bool check = 1;
    for(int i = 0; i < fx_Add.size(); i++) {
        if(get<0>(fx_Add[i])==num_e) {
            get<1>(fx_Add[i]) += num_c;
            if(get<1>(fx_Add[i])==0) {
                fx_Add.erase(fx_Add.begin()+i);
            }
            check = !check;
            break;
        }
    }
    if(check) {
        fx_Add.push_back(make_tuple(num_e,num_c));
    }
    cout << num_c << " " << num_e << endl;
}

void polymult(int num_c, int num_e){
    int temp_num_e;
    int temp_num_c;
    for(int i = 0; i<fx.size();i++){
        temp_num_e = num_e+get<0>(fx[i]);
        temp_num_c = num_c*get<1>(fx[i]);
        if(temp_num_c){
            polyadd(temp_num_c,temp_num_e,temp_fx);
        }
    }
}

void solve(){
    int num_fx;
    int num_c, num_e;
    int num_term;

    in >> num_fx;
    for(int i = 0; i<num_fx; i++){
        in >> num_term;
        if(fx.size()){
            for(int j = 0; j<num_term; j++){
                in >> num_c >> num_e;
                polymult(num_c,num_e);
            }
            fx.clear();
            fx = temp_fx;
            temp_fx.clear();
        }
        else{
            for(int j = 0; j<num_term; j++){
                in >> num_c >> num_e;
                polyadd(num_c,num_e,fx);
            }
        }
        sort(fx.begin(),fx.end(),greater<tuple<int,int>>());
    }
}


int main() {

    solve();
    output();

    return 0;
}
