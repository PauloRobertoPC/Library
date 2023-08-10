#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll calc(ll k){
    ll kk = k*k;
    ll comb = (kk*(kk-1))/2;
    ll eat = 4*(k-1)*(k-2);
    return comb-eat;
}

int main(){
    ll n; cin >> n;
    for(ll i = 1; i <= n; i++){
        cout << calc(i) << "\n";
    }
    return 0;
}
