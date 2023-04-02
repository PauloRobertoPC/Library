#include <bits/stdc++.h>

using namespace std;

#define maxn ll(2e5+10)
#define INF ll(1e16)

typedef long long ll;

ll v[maxn];
pair<ll, ll> seg[4*maxn];
ll lazy[4*maxn];

pair<ll, ll> merge(pair<ll, ll> a, pair<ll, ll> b){
    return {a.first+b.first, max(a.second, b.second)};
}

void build(ll node, ll l, ll r){
    if(l == r){
        seg[node] = {v[l], v[l]};
        return;
    }
    ll mid = (l+r)/2, nxt = node*2;
    build(nxt, l, mid);
    build(nxt+1, mid+1, r);
    seg[node] = merge(seg[nxt], seg[nxt+1]);
}

void push(ll node, ll l, ll r){
    if(lazy[node]){
        seg[node].first += (r-l+1)*lazy[node];
        seg[node].second += lazy[node];
        if(l != r){
            ll nxt = node*2;
            lazy[nxt] += lazy[node];
            lazy[nxt+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(ll node, ll l, ll r, ll x, ll y, ll val){
    push(node, l, r);
    if(l > y || r < x) return;
    if(l >= x && r <= y){
        lazy[node] += val;
        push(node, l, r);
        return;
    }
    ll mid = (l+r)/2, nxt = 2*node;
    update(nxt, l, mid, x, y, val);
    update(nxt+1, mid+1, r, x, y, val);
    seg[node] = merge(seg[nxt], seg[nxt+1]);
}

ll zero(ll node, ll l, ll r){
    push(node, l, r);
    if(seg[node].second < 0) return -1;
    if(l == r) return l;
    ll mid = (l+r)/2, nxt = 2*node;
    ll ans = zero(nxt, l, mid);
    if(ans == -1)
        ans = zero(nxt+1, mid+1, r);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    vector<ll> ans(n+1, -1);
    for(ll i = 1; i <= n; i++) v[i] = -i;
    build(1, 1, n);
    for(ll i = 1; i <= n; i++){
        ll l, r; cin >> l >> r;
        update(1, 1, n, l, r, 1);
        ll zerou = zero(1, 1, n);
        while(zerou != -1){
            ans[zerou] = i;
            update(1, 1, n, zerou, zerou, -INF);
            zerou = zero(1, 1, n);
        }
    }
    for(ll i = 1; i <= n; i++) cout << ans[i] << " "; cout << "\n";
    return 0;
}
// Description: Data Structures - Segtree + Binary Search in Segtree
