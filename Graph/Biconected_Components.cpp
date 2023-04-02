int n, clk, cc;
vector<int> fst, low, vis, st, comp;
vector<vector<int>> adj;

void dfs(int u, int p = -1){
    vis[u] = 1;
    fst[u] = low[u] = clk++; 
    st.emplace_back(u);
    for(int v:adj[u]){
        if(v == p) continue;
        if(!vis[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }else{
            low[u] = min(low[u], fst[v]);
        }
    }
    if(low[u] == fst[u]){
        int v;
        do{
            v = st.back(); st.pop_back();
            comp[v] = cc;
        }while(!st.empty() && v != u);
        ++cc;
    }
}

void find_bi_components(){
    clk = cc = 0;
    st.clear();
    vis.assign(n+1, 0);
    fst.assign(n+1, 0);
    low.assign(n+1, 0);
    comp.assign(n+1, 0);
    for(int u = 1; u <= n; u++)
        if(!vis[u])
            dfs(u);
}
