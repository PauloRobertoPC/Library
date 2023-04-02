#include <bits/stdc++.h>

using namespace std;

#define maxn ll(2e5+10)

typedef long long ll;

ll v[maxn];
ll seg[4*maxn];

ll merge(ll a, ll b){
    if(v[a] >= v[b]) return a;
    return b;
}

void build(ll node, ll l, ll r){
    if(l == r){
        seg[node] = l;
        return;
    }
    ll mid = (l+r)/2, nxt = node*2;
    build(nxt, l, mid);
    build(nxt+1, mid+1, r);
    seg[node] = merge(seg[nxt], seg[nxt+1]);
}

void update(ll node, ll l, ll r, ll pos){
    if(pos < l || pos > r) return;
    if(pos == l && pos == r){
        seg[node] = maxn-1;
        v[pos] = 0;
        return;
    }
    ll mid = (l+r)/2, nxt = node*2;
    update(nxt, l, mid, pos);
    update(nxt+1, mid+1, r, pos);
    seg[node] = merge(seg[nxt], seg[nxt+1]);
}

ll get(ll node, ll l, ll r, ll x ,ll y){
    if(l > y || r < x) return 0; 
    if(l >= x && r <= y) return seg[node];
    ll mid = (l+r)/2, nxt = node*2;
    return merge(get(nxt, l, mid, x, y), get(nxt+1, mid+1, r, x, y));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        for(ll i = 0; i < n; i++) cin >> v[i];
        build(1, 0, n-1);
        ll ans = 0;
        for(ll i = 0; i < n; i++){
            if(v[i]) continue;        
            ll pos = get(1, 0, n-1, 0, i);
            if(pos == maxn-1) continue;
            ans += v[pos];
            update(1, 0, n-1, pos);
        }
        cout << ans << "\n";
    }
    return 0;
}
