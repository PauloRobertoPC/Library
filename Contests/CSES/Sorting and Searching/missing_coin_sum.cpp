#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n; cin >> n;
    vector<ll> v(n);
    for(ll &x:v) cin >> x;
    sort(v.begin(), v.end());
    ll ans = 0;
    for(ll i = 0; i < n; i++)
        if(ans >= v[i]-1)
            ans += v[i];
    cout << ans+1 << "\n";
    return 0;
}
