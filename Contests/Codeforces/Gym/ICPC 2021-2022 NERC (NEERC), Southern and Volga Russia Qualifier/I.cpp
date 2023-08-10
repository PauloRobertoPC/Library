#include <bits/stdc++.h>

using namespace std;

#define maxn int(2e5+10)

int n;
int dad[maxn], sz[maxn], color[maxn];
vector<int> adj[maxn];

void dfs(int u, int p = -1, int c = 0){
    sz[u] = 1;
    color[u] = c;
    for(int v:adj[u])
        if(v != p)
            dad[v] = u, dfs(v, u, c), sz[u] += sz[v];
}

int main(){
    cin >> n;
    int u, v;
    for(int i = 1; i < n; i++){
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(1);
    u = -1;
    for(int i = 1; i <= n; i++){
        if(adj[i].size() <= (n/2) && sz[i] == (n/2))
            u = i;
    }
    if(u == -1){
        cout << "NO\n";
        return 0;
    }
    dfs(u, dad[u], 1);
    cout << "YES\n";
    for(int i = 1; i <= n; i++)
        cout << color[i] << " ";
    cout << "\n";
    return 0;
}
