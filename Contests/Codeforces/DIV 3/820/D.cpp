#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll query(vector<ll> &p, ll l, ll r){
    if(r < l) return 0;
    return p[r]-p[l-1];
}

int main(){
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> v(n+1, 0), p(n+1, 0); ll c;
        for(ll i = 1; i <= n; i++) cin >> c, v[i] -= c;
        for(ll i = 1; i <= n; i++) cin >> c, v[i] += c;
        sort(v.begin()+1, v.end());
        for(ll i = 1; i <= n; i++) p[i] = v[i]+p[i-1];
        ll l = 1, r = n, ans = 0;
        for(; l <= n && query(p, l, n) < 0; l++);
        if(l > n){ 
            cout << "0\n";
            continue;
        }
        l = 1;
        while(l <= r){
            if(l == r) break;
            while(l < r && v[r]+v[l] < 0) l++;
            ans += ((l < r) && (v[l++]+v[r--]) >= 0);
        }
        cout << ans << "\n";
    }
    return 0;
}
