#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, t;
vector<ll> v;

bool ok(ll tm){
    ll aux = t;
    for(ll x:v){
        aux -= tm/x;
        if(aux <= 0)
            return true;
    }
    return false;
}

ll bb(){
    ll l = 0, r = 1e18, mid; ++r;
    while(l < r-1){
        mid = (l+r)/2;
        if(ok(mid)) r = mid;
        else l  = mid;
    }
    return r;
}

int main(){
    cin >> n >> t;
    v.resize(n);
    for(ll &x:v) cin >> x;
    cout << bb() << "\n";
    return 0;
}
