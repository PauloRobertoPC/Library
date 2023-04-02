#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll t; cin >> t;
    while(t--){
        ll n, ans = 0; cin >> n;
        vector<ll> v(n);
        for(ll &x:v) cin >> x;
        vector<bool> ok(n+1, 0);
        vector<ll> pref(n); pref[0] = v[0];
        for(ll i = 1; i < n; i++)
            pref[i] = pref[i-1]+v[i];
        pref.insert(pref.begin(), 0);
        for(int i = 0; i < pref.size(); i++){
            int r = pref[i];
            for(int j = i-2; j >= 0; j--){
                int l = pref[j]; 
                if(r-l >= 1 && r-l <= n)
                    ok[r-l] = 1;
            }
        }
        for(int i = 0; i < n; i++) ans += ok[v[i]];
        cout << ans << "\n";
    } return 0;
}
