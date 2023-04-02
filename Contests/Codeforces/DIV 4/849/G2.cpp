#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, c;

ll calc(vector<array<ll, 4>> &v, vector<ll> &pref, ll rem){
    ll eq1 = c-v[rem][1];
    ll eq2 = c-v[rem][1]+v[rem][0];
    if(eq1 < 0) return 0;
    ll op1 = upper_bound(pref.begin(), pref.begin()+rem-1, eq1) - pref.begin();   
    ll op2 = upper_bound(pref.begin()+rem, pref.end(), eq2) - pref.begin();   
    if(rem && pref[op1] > eq1) //considerar op1 e op2
        return op1+1; 
    return op2;
}

int main(){
    ll t; cin >> t;
    vector<ll> sla = {1, 2, 3, 4};
    while(t--){
        cin >> n >> c;
        vector<array<ll, 4>> v;
        for(ll i = 1, cost; i <= n; i++){
            cin >> cost;
            ll c1 = i+cost;
            ll c2 = n+1-i+cost;
            v.push_back({min(c1, c2), c1, c2, i});
        }
        sort(v.begin(), v.end());
        vector<ll> pref(n);
        pref[0] = v[0][0];
        for(ll i = 1; i < n; i++) pref[i] = pref[i-1]+v[i][0];
        
        ll ans = 0;
        for(ll i = 0; i < n; i++) ans = max(ans, calc(v, pref, i));
        cout << ans << "\n";
    }
    return 0;
}
