#include <bits/stdc++.h>

using namespace std;

#define maxn int(2e5+10)

typedef long long ll;

int sz[maxn], visited[maxn];
vector<int> adj[maxn];

int dfs(int u){
    if(visited[u]) return 0;
    visited[u] = 1;
    int ans = sz[u];
    for(int v:adj[u])
        if(!visited[v])
            ans += dfs(v);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 2; i <= n; i++){
        int dad; cin >> dad;
        adj[dad].emplace_back(i);
    }
    for(int i = 0, dad; i < m; i++){
        cin >> dad;
        ++sz[dad];
    }
    int q; cin >> q;
    while(q--){
        int u; cin >> u;
        cout << dfs(u) << "\n"; 
    }
    return 0;
}
