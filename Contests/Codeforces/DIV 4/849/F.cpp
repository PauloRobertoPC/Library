#include <bits/stdc++.h>

using namespace std;

#define maxn ll(2e5+10)

typedef long long ll;

ll n;
ll v[maxn];
ll seg[4*maxn];
ll lazy[4*maxn];

ll conv(ll num){
    ll ans = 0;
    while(num){
        ans += num%10;
        num /= 10;
    }
    return ans;
}

ll conv(ll num, ll t){
    while(t--){
        if(num < 10) break; 
        num = conv(num);
    }
    return num;
}

ll combine(ll a, ll b){
    return a+b;
}

void build(ll node = 1, ll l = 0, ll r = n-1){
    lazy[node] = 0;
    if(l == r){
        seg[node] = v[l]; 
        return;
    }
    ll mid = (l+r)/2, nxt = 2*node;
    build(nxt, l, mid);
    build(nxt+1, mid+1, r);
    seg[node] = combine(seg[nxt], seg[nxt+1]);
}

void push(ll node, ll l, ll r){
    if(lazy[node]){
        seg[node] = conv(seg[node], lazy[node]); 
        if(l != r){
            ll nxt = 2*node;
            lazy[nxt] += lazy[node];
            lazy[nxt+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(ll x, ll y, ll node = 1, ll l = 0, ll r = n-1){
    push(node, l, r);
    if(l > y || r < x) return;
    if(l >= x && r <= y){
        lazy[node] += 1;
        push(node, l, r);
        return;
    }
    ll mid = (l+r)/2, nxt = 2*node;
    update(x, y, nxt, l, mid);
    update(x, y, nxt+1, mid+1, r);
    seg[node] = combine(seg[nxt], seg[nxt+1]);
}

ll get(ll x, ll y, ll node = 1, ll l = 0, ll r = n-1){
    push(node, l, r);
    if(l > y || r < x) return 0;
    if(l >= x && r <= y) return seg[node];
    ll mid = (l+r)/2, nxt = 2*node;
    return combine(get(x, y, nxt, l, mid), get(x, y, nxt+1, mid+1, r));
}
    
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t; cin >> t;
    while(t--){
        ll q; cin >> n >> q;
        for(ll i = 0; i < n; i++) cin >> v[i];
        build();
        while(q--){
            ll op; cin >> op;
            if(op&1){
                ll l, r; cin >> l >> r; --l; --r;
                update(l, r);
            }else{
                ll pos; cin >> pos; --pos;
                cout << get(pos, pos) << "\n";
            }
        }
    }
    return 0;
}
