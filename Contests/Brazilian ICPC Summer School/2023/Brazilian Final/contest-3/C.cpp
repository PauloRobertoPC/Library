#include <bits/stdc++.h>

using namespace std;

int n, clk;
vector<int> fst, low, vis;
vector<vector<int>> adj;

vector<int> dad, _rank;

void build(){
    dad.assign(n+1, 0); iota(dad.begin(), dad.end(), 0);
    _rank.assign(n+1, 1);
}

int find(int u){
    return (dad[u] == u ? u : dad[u] = find(dad[u]));
}

void join(int u, int v){
    u = find(u), v = find(v);
    if(u != v){
        if(_rank[u] < _rank[v]) swap(u, v);
        dad[v] = dad[u];
        _rank[u] += _rank[v];
    }
}

void dfs(int u, int p = -1){
    vis[u] = 1;
    fst[u] = low[u] = clk++; 
    for(int v:adj[u]){
        if(v == p) continue;
        if(!vis[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > fst[u]){ //(u, v) is a bridge
                //do  something
                join(u, v); 
            }
        }else{
            low[u] = min(low[u], fst[v]);
        }
    }
}

void find_bridge(){
    clk = 0;
    vis.assign(n+1, 0);
    fst.assign(n+1, 0);
    low.assign(n+1, 0);
    for(int u = 1; u <= n; u++)
        if(!vis[u])
            dfs(u);
}

int main(){
    int m, q;
    while(cin >> n >> m >> q, n){
        adj.assign(n+1, vector<int>());
        int u, v;
        while(m--){
            cin >> u >> v;
            adj[u].emplace_back(v); 
            adj[v].emplace_back(u); 
        }
        build();
        find_bridge();
        while(q--){
            cin >> u >> v;
            cout << (find(u) == find(v) ? "Y" : "N") << "\n";
        }
        cout << "-\n";
    }
    return 0;
}
// Description: Bridge and DSU
