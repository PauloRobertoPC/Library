#include <bits/stdc++.h>
#include <queue>

using namespace std;

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

int main(){
    int n; cin >> n;
    map<string, int> mp;
    vector<string> vt(n);
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        mp[s] = i;
        vt[i] = s;
    }
    vector<vector<int>> adj(n, vector<int>(n, 1));
    int r; cin >> r;
    while(r--){
        int tot, pos; cin >> tot >> pos; --pos;
        vector<int> vis(n, 0);
        while(tot--){
            string x; cin >> x; vis[mp[x]] = 1;
        }
        for(int i = 0; i < n; i++){
            if(vis[i]){
                for(int j = 0; j < pos; j++)
                    adj[i][j] = 0;
            }else{
                adj[i][pos] = 0;
            }
        }
    }
    Kuhn::init(n, n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(adj[i][j])
                Kuhn::addEdge(i, j);
    Kuhn::matching();
    for(int i = 0; i < n; i++)
        cout << vt[Kuhn::mb[i]] << " ";
    cout << "\n";
    return 0;
}
