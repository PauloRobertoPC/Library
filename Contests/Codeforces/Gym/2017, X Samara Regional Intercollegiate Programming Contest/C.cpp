#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll r, g, u; 
    ll n, m;
    cin >> r >> g >> u;
    cin >> n >> m;
    ll ans = r+g+u;
    if(r+u > n) ans = min(ans, n);
    if(g+u > m) ans = min(ans, m);
    cout << ans << "\n";
    return 0;
}
