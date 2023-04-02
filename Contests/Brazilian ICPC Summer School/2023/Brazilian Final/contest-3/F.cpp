#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
vector<array<ll, 2>> lr;
vector<vector<ll>> adj, dp;

ll dfs(ll u, ll p, ll choose){
    ll &ans = dp[u][choose];
    if(ans != -1) return ans;
    ans = 0;
    for(ll v:adj[u]){
        if(v != p){
            ll mmax1 = dfs(v, u, 0)+abs(lr[u][choose] - lr[v][0]);
            ll mmax2 = dfs(v, u, 1)+abs(lr[u][choose] - lr[v][1]);
            ans += max(mmax1, mmax2);
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        cin >> n;
        adj.assign(n+1, vector<ll>());
        dp.assign(n+1, vector<ll>(2, -1));
        lr.assign(n+1, array<ll, 2>());
        for(ll i = 1; i <= n; i++) cin >> lr[i][0] >> lr[i][1];
        for(ll i = 1; i < n; i++){
            ll u, v;
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        cout << max(dfs(1, -1, 0), dfs(1, -1, 1)) << "\n";
    }
    return 0;
}
// Description: DP - DP on Tree
