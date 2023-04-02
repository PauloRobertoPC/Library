int n, clk;
vector<int> fst, low, vis;
vector<vector<int>> adj;

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
