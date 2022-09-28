#include <bits/stdc++.h>

using namespace std;

#define maxn ll(1e5+10)

typedef long long ll;

ll n, m;
ll bit[maxn];

void add(ll idx, ll val) {
    for (++idx; idx < maxn; idx += idx & -idx) bit[idx] += val;
}

void range_add(ll l, ll r, ll val) {
    add(l, val);
    add(r + 1, -val);
}

ll poll_query(ll idx) {
    ll ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)
        ret += bit[idx];
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 1; i <= n; i++){
        ll num;
        cin >> num;
        range_add(i, i, num);
    }
    while(m--){
        ll pos; cin >> pos;
        ll val = max(poll_query(pos), 0LL);
        range_add(max(1LL, pos-val), min(maxn-1, pos+val), -1);
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i++)
        ans += max(0LL, poll_query(i));
    cout << ans << "\n";
    return 0;
}
