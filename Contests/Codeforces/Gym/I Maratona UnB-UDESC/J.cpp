#include <bits/stdc++.h>

using namespace std;

#define maxn ll(1e5+10)

typedef long long ll;

ll n, m;
ll v[maxn];

bool ok(ll qtd){
    if(!qtd) return false;
    --qtd;
    return v[qtd] >= m;
}

ll bb(){
    ll l = -1, r = n-1, mid;
    while(l < r-1){
        mid = (l+r)/2;
        if(ok(mid)) r = mid;
        else l = mid;
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < n; i++) cin >> v[i];
    for(ll i = 1; i < n; i++) v[i] += v[i-1];
    ll qtd = m/v[n-1];
    m -= v[n-1]*qtd;
    ll ans = qtd*n;
    if(m) ans += bb();
    cout << ans << "\n";
    return 0;
}
