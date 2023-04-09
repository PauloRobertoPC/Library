#include <bits/stdc++.h>

using namespace std;

#define maxn 1010

int n;
vector<int> adj[maxn];

vector<int> bfs(int s, int nv = 0){
    vector<int> vis(n+1, 0); vis[s] = vis[nv] = 1;
    queue<int> q; q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v:adj[u]){
            if(!vis[v]){
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    return vis;
}

int main(){
    cin >> n;
    vector<pair<int ,int>> p;
    for(int i = 1, u, v; i <= n; i++){
        cin >> u >> v;
        adj[u].emplace_back(i);
        adj[v].emplace_back(i);
        p.emplace_back(u, v);
    }
    for(int i = 1; i <= n; i++){
        vector<int> a = bfs(p[i-1].first, i);
        vector<int> b = bfs(p[i-1].second, i);
        vector<int> root(n+1, 0);
        for(int j = 1; j <= n; j++)
            if(i != j && a[j] && b[j])
                root[j] = 1;
        vector<int> c = bfs(i);
        bool ok = false;
        for(int j = 1; j <= n; j++)
            if(i != j && root[j] && c[j])
                ok = true;
        cout << (ok ? "Y" : "N");
    }
    cout << "\n";
    return 0;
}
