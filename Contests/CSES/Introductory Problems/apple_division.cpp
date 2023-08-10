#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n; cin >> n;
    vector<ll> v(n);
    for(ll &x:v) cin >> x;
    ll ans = 1e18;
    ll lim = 1<<n;
    for(ll i = 0; i < lim; i++){
        ll sum1 = 0, sum2 = 0;
        for(ll j = 0; j < n; j++){
            if(i&(1<<j)) sum1 += v[j];
            else sum2 += v[j];
        }
        ans = min(ans, abs(sum1-sum2));
    }
    cout << ans << "\n";
    return 0;
}
