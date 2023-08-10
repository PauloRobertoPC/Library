#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n, sum = 0; cin >> n;
    vector<ll> v(n);
    for(ll &x:v) cin >> x, sum += x;
    sort(v.begin(), v.end());
    ll aux = 0, comp, ans = 1e18;
    for(ll i = 0; i < n; i++){
        aux += v[i];
        comp = sum-aux;
        ans = min(ans, ((i+1)*v[i]-aux)+(comp-(n-i-1)*v[i]));
    }
    cout << ans << "\n";
    return 0;
}
