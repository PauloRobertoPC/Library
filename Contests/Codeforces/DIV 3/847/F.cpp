#include <bits/stdc++.h>

using namespace std;

#define INF int(1e6)
#define maxn int(2e5+10)
#define LOG 20

int ans;
int lvl[maxn], parent[maxn][LOG];
int sz[maxn], used[maxn], dad[maxn];
vector<int> mmin;
vector<vector<int>> adj;

void dfs(int u, int p, int h){
   lvl[u] = h;
   parent[u][0] = p;
   for(int i = 1; i < LOG; i++)
      if(parent[u][i-1] != -1)
         parent[u][i] = parent[parent[u][i-1]][i-1];
   for(auto v:adj[u])
      if(v != p)
         dfs(v, u, h+1);
}

int up(int u, int k){
   for(int i = LOG-1; i >= 0; i--)
      if(k&(1<<i) && parent[u][i] != -1)
         u = parent[u][i];
   return u;
}

int LCA(int u, int v){
   if(lvl[u] < lvl[v]) swap(u, v);
   u = up(u, lvl[u]-lvl[v]); 
   if(u == v) return u;
   for(int i = LOG-1; i >= 0; i--)
      if(parent[u][i] != parent[v][i])
         u = parent[u][i], v = parent[v][i];
   return parent[u][0];
}

int distEdge(int u, int v){
   return lvl[u]+lvl[v]-2*lvl[LCA(u, v)];
}

void calcSize(int u, int p){
    sz[u] = 1;
    for(int v:adj[u])
        if(v != p && !used[v]) 
            calcSize(v, u), sz[u] += sz[v]; 
}

pair<int, int> calcCentroid(int u, int p, int tot){
    for(int v:adj[u])
    if(v != p && !used[v] && sz[v]*2 > tot)
        return calcCentroid(v, u, tot);
    for(int v:adj[u]) if(v != p && !used[v] && sz[v]*2 >= tot) return {u, v};
    return {u, u};
}

pair<int, int> centroid(int u){
    calcSize(u, -1);
    pair<int, int> c = calcCentroid(u, -1, sz[u]);
    used[c.first] = 1;
    return c;
}

int centroidTree(int u){
    u = centroid(u).first;
    for(int v:adj[u])
    if(!used[v]) 
        dad[centroidTree(v)] = u;
    return u;
}

void att(int root, int v){
    int aux = v;
    ans = min(ans, mmin[v]);
    mmin[v] = 0;
    do{
        v = dad[v];
        if(!v) break;
        int dist = distEdge(v, aux);
        ans = min(ans, mmin[v]+dist);
        mmin[v] = min(mmin[v], dist);
    }while(v != root);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, c; cin >> n >> c;
        ans = INF;
        adj.assign(n+1, vector<int>());
        for(int i = 0; i <= n+5; i++){
            used[i] = sz[i] = lvl[i] = dad[i] = 0;
            for(int j = 0; j < LOG; j++) parent[i][j] = -1;
        }
        vector<int> q(n-1);
        for(int &x:q) cin >> x;
        for(int i = 1, u, v; i < n; i++){
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        
        dfs(1, -1, 1);
        
        int root = centroidTree(1); 
        mmin.assign(n+1, INF);
        
        
        att(root, c);
        for(int &v:q){
            att(root, v);
            cout << ans << " ";
        }
        cout << "\n";

    }
    return 0;
}
