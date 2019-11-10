
#include <bits/stdc++.h>
using namespace std;
typedef struct { string name ;  vector<int> report; }  Stud ;


ifstream in("rank.inp");
ofstream out("rank.out");

bool myfun ( Stud a, Stud b)   {
    if((a.report.size())==( b.report.size())){
        if((a.report.back())==(b.report.back())){
            for(auto i = 0; i<a.report.size()-1;i++){
                if(*(a.report.begin()+i) > *(b.report.begin()+i)){
                    return 1;
                }
                else if(*(a.report.begin()+i) < *(b.report.begin()+i)){
                    return 0;
                }
            }
            if((a.name).compare(b.name) < 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        return ((a.report.back())>(b.report.back()));
    }
    return ((a.report.size())>( b.report.size())) ;
}

void outclass( vector < Stud > Pclass ){
    for(auto s : Pclass) {
        out << s.name <<"\n";
    }
}

int main() {

    int i, N, score ;
    int sum = 0;
    string xname ;
    Stud   body ;
    vector < Stud > Pclass ;


    in >> N ;

    for(i=0 ; i < N ; i++){
        in >> xname ;
        body.name = xname ;
        body.report.clear();
        sum = 0;
        while(1){
            in >> score ;
            sum += score ;
            if( score <= 0) break ;
            else {
                body.report.push_back( score ) ;
            }
        } // end of while()
        body.report.push_back( sum ) ;
        sort( body.report.begin(),  body.report.end() ) ;
        Pclass.push_back( body );
    } // end of for()
    sort( Pclass.begin(), Pclass.end(), myfun ) ;
    outclass( Pclass ) ;

} // end of main ( )
