#include <bits/stdc++.h>

using namespace std;

#define maxn int(1e5+10)

int cc;
int dad[maxn], _rank[maxn];

void build(){
    for(int i = 0; i < maxn; i++) dad[i] = i, _rank[i] = 1;
}

int find(int u){
    return dad[u] == u ? u : dad[u] = find(dad[u]);
}

void join(int u, int v){
    u = find(u), v = find(v);
    if(u != v){
        if(_rank[u] < _rank[v]) swap(u, v);
        dad[v] = u;
        _rank[u] += _rank[v];
        --cc;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    cc = n;
    vector<pair<int, int>> e(m+1);
    for(int i = 1; i <= m; i++) cin >> e[i].first >> e[i].second;
    int q; cin >> q; 
    vector<int> qs(q), ans(q);
    set<int> cj;
    for(int &x:qs) cin >> x, cj.insert(x);
    build();
    for(int i = 1; i <= m; i++) if(!cj.count(i)) join(e[i].first, e[i].second);
    for(int i = q-1; i >= 0; i--){
        ans[i] = cc; 
        int j = qs[i];
        join(e[j].first, e[j].second);
    }
    for(int x:ans) cout << x << " "; cout << "\n";
    return 0;
}
// Description: Data Structure - DSU + Backward Preprocess
