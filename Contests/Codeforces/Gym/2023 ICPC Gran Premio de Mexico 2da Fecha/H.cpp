#include <bits/stdc++.h>

using namespace std;

#define maxn int(1e6+10)

int n;
int g[maxn], ans[maxn];
vector<int> adj[maxn];
map<int, int> cj;

void dfs(int u){
    if(u != 0)
        ++cj[g[u]];
    ans[u] = cj.size();
    for(int v:adj[u])
        dfs(v);
    cj[g[u]]--;
    if(cj[g[u]] == 0) cj.erase(g[u]);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int v; cin >> v;
        adj[v].emplace_back(i);
    }
    for(int i = 1; i <= n; i++) cin >> g[i];
    dfs(0);
    for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << "\n";
    return 0;
}
