#include <bits/stdc++.h>

using namespace std;

int id;
map<map<int, int>, int> mID;
vector<vector<int>> adj;

pair<int, bool> dfs(int u, int p){
    vector<pair<int, bool>> child;
    map<int, int> mV;
    for(int v:adj[u]){
        if(v == p) continue;
        child.emplace_back(dfs(v, u));
        ++mV[child.back().first]; 
    }
    bool ok = true; int odd = 0;
    for(auto par:mV) odd += ((par.second&1) != 0);
    for(auto par:child){
        if((mV[par.first]&1) != 0){
            ok = par.second;
            break;
        }
    }
    if(!mID.count(mV)) mID[mV] = id++;
    return {mID[mV], (ok && odd <= 1)};
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        id = 0; mID.clear();
        adj.assign(n+1, vector<int>());
        for(int i = 1, u, v; i < n; i++){
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        cout << (dfs(1, -1).second ? "YES" : "NO") << "\n";
    }
    return 0;
}

// Description: Graph - Tree Isomorphism
