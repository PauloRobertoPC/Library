#include <bits/stdc++.h>

using namespace std;

#define maxn int(2e4+100)

int n, m;
int visited[maxn];
vector<int> adj[maxn];

void dfs(int u){
    visited[u] = 1;
    // cout << u << "\n";
    for(int v:adj[u]){
        if(!visited[v] && adj[v].size() <= 2){
            dfs(v);
        }
    }
}

int main(){
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    for(int i = 1; i <= n; i++)
        if(adj[i].size() == 1 || adj[i].size() >= 5)
            dfs(i);
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans += (!visited[i]);
    cout << ans << "\n";
    return 0;
}
