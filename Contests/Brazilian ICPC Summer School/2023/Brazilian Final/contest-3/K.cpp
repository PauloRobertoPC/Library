#include <bits/stdc++.h>

using namespace std;

#define maxn int(3e5+10)

int n, m, clk, cc, a, b, ans;
bool art[maxn]; stack<int> st;
int fst[maxn], low[maxn], vis[maxn], comp[maxn];
vector<pair<int, int>> adj[maxn], tree[maxn];

void dfs(int u, int p = -1){
    st.push(u);
    vis[u] = 1;
    fst[u] = low[u] = clk++;
    for(auto [v, z]:adj[u]){
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
            v = st.top(); st.pop();
            comp[v] = cc;
        }while(!st.empty() && v != u);
        ++cc;
    }
}

void dfs2(int u, int p, int tot){
    tot += art[u];
    if(u == b) ans = tot;
    for(auto [v, w]:tree[u])
        if(v != p)
            dfs2(v, u, tot+w);
    tot -= art[u];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    while(m--){
        int u, v, z;
        cin >> u >> v >> z;
        adj[u].emplace_back(v, z);
        adj[v].emplace_back(u, z);
    }
    dfs(1);
    for(int u = 1; u <= n; u++){
        for(auto [v, z]:adj[u]){
            if(comp[u] == comp[v]){
                art[comp[u]] |= z; 
            }else{
                tree[comp[u]].emplace_back(comp[v], z);
            }
        }
    }
    cin >> a >> b;
    a = comp[a], b = comp[b];
    dfs2(a, -1, 0);
    cout << (ans ? "YES" : "NO") << "\n";
    return 0;
}
// Description: Graph - Biconected Components + Condesation Tree
