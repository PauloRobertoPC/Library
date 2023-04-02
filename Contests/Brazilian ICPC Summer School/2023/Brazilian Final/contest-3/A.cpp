#include <bits/stdc++.h>

using namespace std;

#define maxn ll(1e5+10)

typedef long long ll;

ll a[maxn], dad[maxn], _rank[maxn];
vector<ll> adj[maxn];

void build(){
    for(ll i = 0; i < maxn; i++){
        dad[i] = i;
        _rank[i] = 1;
    }
}

ll findSet(ll u){
    return ((dad[u] == u) ? u : dad[u] = findSet(dad[u]));
}

void unionSet(ll u, ll v){
    u = findSet(u), v = findSet(v);
    if(u == v) return;
    if(_rank[u] < _rank[v]) swap(u, v);
    dad[v] = u;
    _rank[u] += _rank[v];
}

int main(){
    ll n, m; cin >> n >> m;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    vector<tuple<ll, ll, ll>> e(m);  
    for(auto &[w, u, v]:e){
        cin >> u >> v;
        w = min(a[u], a[v]);
    }
    sort(e.rbegin(), e.rend());
    build();
    ll sum = 0;
    for(auto &[w, u, v]:e){
        if(findSet(u) != findSet(v)){
            sum += w*_rank[findSet(u)]*_rank[findSet(v)];
            unionSet(u, v);
        }
    }
    cout << fixed << setprecision(10) << 2.0*sum/(n*(n-1)) << "\n";
    return 0;
}
//Description: MST - Minimum Spanning Tree maximize the edge of min cost and...
//                   Maximum Spanning Tree minimize the edge of max cost
