#include <bits/stdc++.h>

using namespace std;

#define maxn ll(1e5+10)

typedef long long ll;
typedef pair<ll, ll> ii;

ll n, q;
ll v[maxn];
ii seg[4*maxn];
ll lazy1[4*maxn];
ll lazy2[4*maxn];

ii combine(ii a, ii b, ll shift){
   return ii(a.first+b.first, a.second+b.second+b.first*shift);
}

void build(ll node, ll l, ll r){
    lazy1[node] = lazy2[node] = LLONG_MAX;
    if(l == r){
        seg[node] = {v[l], v[l]};
        return;
    }
    ll mid = (l+r)/2, nxt = node*2;
    build(nxt, l, mid);
    build(nxt+1, mid+1, r);
    seg[node] = combine(seg[nxt], seg[nxt+1], mid-l+1);
}

void push(ll node, ll l, ll r){
    if(lazy1[node] != LLONG_MAX || lazy2[node] != LLONG_MAX){
        ll t_llervalo = r-l+1;
        ll pa = ((1+t_llervalo)*t_llervalo)/2;
        if(lazy2[node] != LLONG_MAX)
            seg[node] = {t_llervalo*lazy2[node], lazy2[node]*pa};
        if(lazy1[node] != LLONG_MAX){
            seg[node].first += t_llervalo*lazy1[node];
            seg[node].second += lazy1[node]*pa;
        }
        if(l != r){
            ll nxt = node*2;
            if(lazy1[node] != LLONG_MAX){
                lazy1[nxt] += lazy1[node];
                lazy1[nxt+1] += lazy1[node];
            }
            lazy2[nxt] = lazy2[node];
            lazy2[nxt+1] = lazy2[node];
        }
        lazy1[node] = lazy2[node] = LLONG_MAX;
    }
}

void update(ll node, ll l, ll r, ll x, ll y, ll val, ll t){
    push(node, l, r);
    if(l > y || r < x) return;
    if(l >= x && r <= y){
        if(t==1) lazy1[node] = val;
        else{
            lazy2[node] = val;
            lazy1[node] = LLONG_MAX;
            if(l != r)
                lazy1[2*node] = lazy1[2*node+1] = LLONG_MAX;
        }
        push(node, l, r);
        return;
    }
    ll mid = (l+r)/2, nxt = node*2;
    update(nxt, l, mid, x, y, val, t);
    update(nxt+1, mid+1, r, x, y, val, t);
    seg[node] = combine(seg[nxt], seg[nxt+1], mid-l+1);
}

ii get(ll node, ll l, ll r, ll x, ll y){
    if(l > y || r < x) return {0, 0};
    if(l >= x && r <= y) return seg[node];
    ll mid = (l+r)/2, nxt = node*2;
    ll shift = max(mid-max(l, x)+1LL, 0LL);
    return combine(get(nxt, l, mid, x, y), get(nxt+1, mid+1, r, x, y), shift);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(ll i = 0; i < n; i++) cin >> v[i];
    build(1, 0, n-1);
    while(q--){
        ll op, l, r;
        cin >> op >> l >> r; --l; --r;
        if(op == 1){
            ll x; cin >> x;
            update(1, 0, n-1, l, r, x, 1);
        }else if(op == 2){
            ll x; cin >> x;
            update(1, 0, n-1, l, r, x, 2);
        }else{
            ii par = get(1, 0, n-1, l, r);
            cout << (par.first == 0 || par.second%par.first == 0 ? "Yes" : "No") << "\n";
        }
    }
    return 0;
}
