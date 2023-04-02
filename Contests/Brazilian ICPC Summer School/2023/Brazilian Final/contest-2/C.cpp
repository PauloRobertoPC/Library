#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n; cin >> n;
    vector<ll> v(n);
    for(ll &x:v) cin >> x;
    unordered_map<ll, ll> mp;
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < n; j++)
            for(ll k = 0; k < n; k++)
                ++mp[v[i]*v[j]+v[k]];
                    
    ll ans = 0;
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < n; j++)
            for(ll k = 0; k < n; k++)
                if(v[k] != 0)
                    ans += mp[(v[i]+v[j])*v[k]];     
    cout << ans << "\n";
    return 0;
}
// Description: Math + Algebra
