
#include <bits/stdc++.h>
using namespace std;
typedef struct { string name ;  vector<int> report; }  Stud ;

bool myfun ( Stud a, Stud b)   {
    return ((a.report.size())>( b.report.size())) ;
} // 비교 함수

void outclass( vector < Stud > Pclass ){
    for(auto s : Pclass) {
        cout << "\n name= " << s.name ;
        for( auto t: s.report)
            cout << " " << t ;
    }
}

int main() {

    int i, N, score ;
    string xname ;
    Stud   body ;
    vector < Stud > Pclass ;

    ifstream in("rank01.txt");

    in >> N ; cout << "\n N= " << N ;

    for(i=0 ; i < N ; i++){
        in >> xname ; cout << "\n name= " << xname ;
        body.name = xname ;
        body.report.clear();
        while(1){
            in >> score ;
            if( score <= 0) break ;
            else {
                body.report.push_back( score ) ;
                cout << " " << score ;
            }
        } // end of while()
        sort( body.report.begin(),  body.report.end() ) ;
        Pclass.push_back( body );
    } // end of for()

    cout << "\n\n After Sorting() ------ \n" ;
    sort( Pclass.begin(), Pclass.end(), myfun ) ;
    outclass( Pclass ) ;

} // end of main ( )
