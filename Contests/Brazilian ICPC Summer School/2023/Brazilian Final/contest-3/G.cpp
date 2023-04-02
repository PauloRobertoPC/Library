#include <bits/stdc++.h>

using namespace std;

#define maxn int(2e5+10)

vector<int> adj[maxn];

int main(){
    int n, m; cin >> n >> m; 
    int u, v;
    while(m--){
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    u = v = maxn;
    for(int i = 1; i <= n; i++)
        if(adj[i].size() < v)
            u = i, v = adj[i].size();
    vector<int> ans(n+1, 1);
    ans[u] = 0;
    for(int v:adj[u]) ans[v] = 0;
    for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << "\n";
    return 0;
}
// Description: Graph - Minimum Vertex Degree
