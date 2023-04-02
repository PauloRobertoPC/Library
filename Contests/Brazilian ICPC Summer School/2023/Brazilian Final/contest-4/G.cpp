#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

const ld EPS = 1e-9;
const ld INF = 1e9;

int main(){
    int t; cin >> t;
    while(t--){
        int b1, p1, b2, p2;
        cin >> b1 >> p1 >> b2 >> p2;

        ld ans1, ans2;
        if(b1) ans1 = p1*log(b1);
        if(b2) ans2 = p2*log(b2);
        
        if(!b1 && !b2) ans1 = ans2 = -INF;     
        else if(!b1) ans1 = -INF;     
        else if(!b2) ans2 = -INF;     

        if(abs(ans1-ans2) < EPS)
            cout << "Lazy\n";
        else if(ans1+EPS < ans2)
            cout << "Congrats\n";
        else
            cout << "HaHa\n";
    }
    return 0;
}
// Description: Math - Exponetiation is the inverse of Logarithm
