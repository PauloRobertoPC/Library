#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> divisors(int n){
    vector<int> d;
    int lim = sqrt(n);
    for(int i = 1; i <= lim; i++){
        if(n%i == 0){
            d.emplace_back(i);
            d.emplace_back(n/i);
        }
    }
    return d;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        auto d = divisors(n);
        ll lcm = 1e18, x = -1, y = -1;
        for(int dv:d){
            ll a = dv, b = n-dv;
            if(a <= 0 || b <= 0) continue;
            ll lcm2 = a*b/__gcd(a, b);
            if(lcm2 < lcm){
                lcm = lcm2;
                x = a;
                y = b;
            }
        }
        // cout << n << ": " << lcm << " -> " << x << " " << y << "\n";
        cout << x << " " << y << "\n";
    }
    return 0;
}
