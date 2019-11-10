#include <bits/stdc++.h>

using namespace std;

int main() {

    ifstream in("polyadd.inp");
    ofstream out("polyadd.out");
    vector < tuple < int, int > > fx;
    int num_fun, num_term;
    int num_c, num_e;
    bool check = true;

    in >> num_fun;
    for(int i = 0; i < num_fun; i++){
        in >> num_term;
        for(int j = 0; j < num_term; j++){
            in >> num_c >> num_e;
            check = true;
            for(int k = 0; k < fx.size(); k++){
                if(get<0>(fx[k])==num_e){
                    get<1>(fx[k]) += num_c;
                    if(get<1>(fx[k])==0){
                        fx.erase(fx.begin()+k);
                    }
                    check = !check;
                    break;
                }
            }
            if(check){
                fx.push_back(make_tuple(num_e,num_c));
            }
        }
    }
    sort(fx.begin(),fx.end(),greater<tuple<int,int>>());
    out << fx.size() << endl;
    if(fx.size()){
        for(int i = 0; i < fx.size(); i++){
            out << get<1>(fx[i]) << " " << get<0>(fx[i]) << endl;
        }
    }
    else{
        out << "0 0";
    }


    in.close();
    out.close();

    return 0;
}
