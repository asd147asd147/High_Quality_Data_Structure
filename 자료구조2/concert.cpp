#include <bits/stdc++.h>

using namespace std;

int main() {

    vector < tuple<double, double, double, double, double> > ranking;
    vector < tuple<double, double> > toilet;
    vector < tuple<double, double, double, double, double> > check;

    ifstream in("concert.inp");
    ofstream out("concert.out");

    double STAGE_p, STAGE_q;
    double t_x, t_y;
    int SIZE_x, SIZE_y;
    double dist_temp = 0;
    double dist_temp_t[4] = {0,};
    double q_x, q_y;
    double dist_q;
    double dist_q_t[4] = {0,};

    int cnt = 0;

    in >> SIZE_x >> SIZE_y;
    in >> STAGE_p >> STAGE_q;

    for(int i = 0; i < 4; i++){
        in >> t_x >> t_y;
        toilet.push_back(make_tuple(t_x, t_y));
    };

    for(int i = 1; i <= SIZE_x; i++){
        for(int j = 1; j <= SIZE_y; j++){
            if(i != STAGE_p || j != STAGE_q){
                dist_temp = 0;
                dist_temp = pow((double)i-STAGE_p,2)+pow((double)j-STAGE_q,2);
                for(int k = 0; k < 4; k++){
                        if(i == get<0>(toilet[k]) && j == get<1>(toilet[k])){
                                break;
                        }
                        dist_temp_t[k] = pow((double)i-get<0>(toilet[k]),2)+pow((double)j-get<1>(toilet[k]),2);
                        if(k == 3){
                            ranking.push_back(make_tuple(dist_temp,dist_temp_t[0],dist_temp_t[1],dist_temp_t[2],dist_temp_t[3]));
                        }
                }
            }
        }
    }
    sort(ranking.begin(),ranking.end());
    for(int i = 0; i < 3; i++){
        in >> q_x >> q_y;
        dist_q = 0;
        dist_q = pow((double)q_x-STAGE_p,2)+pow((double)q_y-STAGE_q,2);
        for(int k = 0; k < 4; k++){
                dist_q_t[k] = pow((double)q_x-get<0>(toilet[k]),2)+pow((double)q_y-get<1>(toilet[k]),2);
        }
        check.push_back(make_tuple(dist_q,dist_q_t[0],dist_q_t[1],dist_q_t[2],dist_q_t[3]));
    }

    for(int j = 0; j < 3; j++){
        for(int i = 0; i < ranking.size(); i++){
            if(ranking[i] == check[j]){
                cnt = i+1;
                out << cnt << " ";
            }
        }
    }
    in.close();
    out.close();
    return 0;
}
