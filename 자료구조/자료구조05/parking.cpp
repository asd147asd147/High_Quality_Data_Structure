#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef long long ll;

int INIT_SLOT = 0;
int CURR_SLOT = 0;
int MOVE_CAR = 0;
int CURR_CAR = 0;

vector < ll > parking;
ifstream in("parking.inp");
ofstream out("parking.out");

void input() {
    in >> INIT_SLOT >> MOVE_CAR;
    CURR_SLOT = INIT_SLOT;
}

void output() {
    int slot_num = 1;
    for(auto i = parking.cbegin(); i<parking.cend(); i++,slot_num++) {
        if(*i != 0) {
            out << slot_num << " " << *i << endl;
        }
    }
}

int find_car(ll car_num) {
    int slot_num = 0;
    car_num *= -1;
    for(auto i = parking.cbegin(); i<parking.cend(); i++,slot_num++) {
        if(*i == car_num) {
            return slot_num;
        }
    }
    return -1;
}

int empty_slot() {
    int slot_num = 0;
    for(auto i = parking.cbegin(); i<parking.cend(); i++,slot_num++) {
        if(*i == 0) {
            return slot_num;
        }
    }
    return -1;
}

void sort_car() {
    int slot_num = 0;
    vector < ll > temp;
    for(auto i = parking.begin(); i<parking.cend(); i++) {
        if(*i != 0){
            temp.push_back(*i);
        }
    }
    parking.clear();
    parking = temp;
}

void solve() {

    ll car_num;
    int check_slot_num = 0;

    parking.resize(INIT_SLOT);
    for(int i = 0; i < MOVE_CAR; i++){
        in >> car_num ;
        if(car_num > 0){
            if(CURR_CAR == CURR_SLOT){
                CURR_SLOT *= 2;
                parking.resize(CURR_SLOT);
            }
            check_slot_num = empty_slot();
            parking[check_slot_num] = car_num;
            CURR_CAR++;
        }
        else{
            check_slot_num = find_car(car_num);
            if(check_slot_num != -1){
                parking[check_slot_num] = 0;
                CURR_CAR--;
            }
            if(CURR_CAR == CURR_SLOT/3){
                sort_car();
                if(CURR_SLOT/2 >= INIT_SLOT){
                    CURR_SLOT /= 2;
                }
                else{
                    CURR_SLOT = INIT_SLOT;
                }
                parking.resize(CURR_SLOT);
            }
        }
    }

}


int main() {
    input();

    solve();

    output();

    return 0;
}
