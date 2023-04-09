#include <bits/stdc++.h>

using namespace std;

#define maxn 110

mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());

namespace Kuhn{
    int na, nb;
    vector<vector<int>> adj;
    vector<int> vis, ma, mb;
    void init(int na1, int nb1){
        na = na1, nb = nb1;
        adj.assign(na, vector<int>());
        vis.assign(na + nb, 0);
        ma.assign(na, -1);
        mb.assign(nb, -1);
    }
    void addEdge(int a, int b) { 
        adj[a].push_back(b); 
    }
    bool dfs(int u) {
        vis[u] = 1;
        for (int to : adj[u]){
            if(vis[na+to]) 
                continue;
            vis[na+to] = 1;
            if (mb[to] == -1 or dfs(mb[to])) {
                ma[u] = to, mb[to] = u;
                return true;
            }
        }
        return false;
    }
    int matching() {
        int ans = 0, c = 1;
        for (auto& v: adj) 
        shuffle(v.begin(), v.end(), rng);
        while (c) {
            for (int j = 0; j < nb; j++) 
                vis[na+j] = 0;
            c = 0;
            for (int i = 0; i < na; i++)
                if (ma[i] == -1 and dfs(i))
                    ans++, c = 1;
        }
        return ans;
    }
};

int n, m;
vector<int> adj1[maxn], adj2[maxn];
int dp[maxn][maxn][maxn];

bool solve(int t1, int p1, int t2, int p2){
    if(dp[t1][p1][t2] != -1)
        return dp[t1][p1][t2];

    dp[t1][p1][t2] = 1;

    vector<pair<int, int>> e;
    for(int u:adj1[t1]){
        if(u == p1) continue;
        for(int v:adj2[t2]){
            if(v == p2) continue;
            if(solve(u, t1, v, t2))
                e.emplace_back(u, v);
        }
    }
    Kuhn::init(n, m);
    for(auto &[u, v]:e)
        Kuhn::addEdge(u, v);
    if(Kuhn::matching() != adj2[t2].size()-(t2!=p2))
        dp[t1][p1][t2] = 0;
    return dp[t1][p1][t2];
}

int main(){
    cin >> n;
    for(int i = 1, u, v; i < n; i++){
        cin >> u >> v; --u; --v;
        adj1[u].emplace_back(v);
        adj1[v].emplace_back(u);
    }
    cin >> m;
    for(int i = 1, u, v; i < m; i++){
        cin >> u >> v; --u; --v;
        adj2[u].emplace_back(v);
        adj2[v].emplace_back(u);
    }

    memset(dp, -1, sizeof(dp));  

    bool ok = false;
    for(int i = 0; i < n; i++)
        ok |= solve(i, i, 0, 0);

    cout << (ok ? 'Y' : 'N') << "\n";

    return 0;
}
