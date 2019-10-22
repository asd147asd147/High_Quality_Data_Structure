#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("1.inp");
ofstream out("1.out");

vector < vector < int > > vin;
vector < int > vtemp;

int main(){
    int temp;
    while((in >> temp)){
        if(temp == 0){
            vin.push_back(vtemp);
            vtemp.clear();
        }
        else{
            vtemp.push_back(temp);
        }
    }
    int first = 0;
    for(int i = 0; i < vin.size(); i++){
        for(int j = 0; j < vin[i].size(); j++){
            if(i == 0 && j == 0){
                first = vin[i][j];
            }
            else if(j == 0){
                cout << vin[i][j] << " 0 " << endl;
            }
            else{
                cout << vin[i][j] << " ";
            }
        }
    }
    cout << first << " 0 ";

    return 0;
}
