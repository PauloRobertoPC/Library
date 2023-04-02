#include <bits/stdc++.h>

using namespace std;

#define maxn int(1e5+10)

//DSU
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
    }
}

int n, m;
int ans[maxn];
vector<tuple<int, int, int, int>> e;
bool bridge[maxn];
int fst[maxn], low[maxn], clk;
vector<pair<int, int>> adj[maxn];

void dfs(int u, int p = -1){
    fst[u] = low[u] = clk++;
    for(auto [v, id]:adj[u]){
        if(v == p) continue;
        if(!fst[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > fst[u]){
                bridge[id] = 1; 
                // cout << "BRIDGE: " << u << " " << v << "\n";
            }
        }else{
            low[u] = min(low[u], fst[v]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m; 
    int u, v, w, id;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        e.emplace_back(w, u, v, i);
    }
    clk = 1;
    build();
    sort(e.begin(), e.end());
    for(int i = 0, j = 0; i < m; i = j){
        int val; tie(val, u, v, w) = e[j];
        map<pair<int, int>, int> cnt;
        vector<int> ids, vert;
        while(j < m){
            tie(w, u, v, id) = e[j];
            u = find(u), v = find(v);
            if(w != val) break;
            if(find(u) == find(v)){
                ans[id] = -1;
            }else{
                ++cnt[{u, v}]; ++cnt[{v, u}];
                adj[u].emplace_back(v, id);
                adj[v].emplace_back(u, id);
                vert.emplace_back(u);
                vert.emplace_back(v);
                ids.emplace_back(j);
            }
            ++j;
        }
        for(int x:vert) if(!fst[u]) dfs(x);
        for(int x:vert) fst[x] = low[x] = 0, adj[x].clear();
        for(int edge:ids){
            tie(w, u, v, id) = e[edge];
            u = find(u), v = find(v);
            ans[id] = bridge[id] && cnt[{u, v}] < 2;
        }
        for(int edge:ids){
            tie(w, u, v, id) = e[edge];
            join(u, v);
        }
    }
    for(int i = 0; i < m; i++){
        if(ans[i] == -1) cout << "none\n"; 
        else if(ans[i] == 0) cout << "at least one\n";
        else cout << "any\n";
    }
    return 0;
}
