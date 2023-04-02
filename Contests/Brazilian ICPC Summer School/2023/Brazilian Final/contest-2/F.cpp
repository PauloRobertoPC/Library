#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll binpow(ll b, ll p, ll m){
    ll ans = 1;
    while(p){
        if(p&1) ans = (ans*b)%m;
        p >>= 1;
        b = (b*b)%m;
    }
    return ans;
}

int main(){
    //
    ll b, p, m;
    while(cin >> b >> p >> m){
        cout << binpow(b, p, m) << "\n";
    }
    return 0;
}
// Description: Math - Binary Exponentiation
