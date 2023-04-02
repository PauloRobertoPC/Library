#include <bits/stdc++.h>

using namespace std;

#define INF int(3e5)

typedef long long ll;

vector<int> tokens, bonus;
vector<int> dist, cc;
vector<vector<int>> adj;

void bfs(int u){
    vector<int> seen;
    dist[u] = 0;
    queue<int> q; q.push(u);
    while(!q.empty()){
        u = q.front(); q.pop();
        seen.emplace_back(u);
        for(int v:adj[u]){
            if(dist[v] == INF && bonus[v]){
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }
    for(int x:seen) cc[x] = seen.size();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for(int k = 1; k <= t; k++){
        int n, m;
        cin >> n >> m;
        adj.assign(n+1, vector<int>());
        dist.assign(n+1, INF);
        cc.assign(n+1, INF);
        tokens.assign(n+1, 0);
        bonus.assign(n+1, 0);
        int p, b;
        cin >> p >> b;
        bool ok = false;
        for(int i = 0, num; i < p; i++){
            cin >> num;
            ok |= (num == 1);
            tokens[num] = 1;
        }
        for(int i = 0, num; i < b; i++){
            cin >> num;
            bonus[num] = 1;
        }
        int u, v;
        while(m--){
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        //How find the vertex 1 walking in vertices with bonus
        bfs(1);
        vector<int> find_one(n+1, 0);
        for(int u = 1; u <= n; u++)
            if(dist[u] != INF)
                find_one[u] = 1;
        //Calc the size of each component that does not find 1
        for(int u = 1; u <= n; u++)
            if(bonus[u] && dist[u] == INF)
                bfs(u);
        //calc the min dist to 1
        int dmin = INF, vmin = INF;
        for(int u = 1; u <= n; u++){
            if(tokens[u]){
                for(int v:adj[u]){
                    int d = (find_one[u] ? dist[u] : (find_one[v] ? 1+dist[v] : INF));
                    if(d < dmin){
                        dmin = d;
                        vmin = u;
                    }
                }
            }
        }
        ok |= (dmin <= 1);
        //calc how much we can walk with the other tokens
        long long qtd_steps = 0;
        for(int u = 1; u <= n; u++){
            if(tokens[u] && u != vmin){
                long long mmax = 0; 
                for(int v:adj[u])
                    if(dist[v] != INF)
                        mmax = max(mmax, ll(cc[v] == 1 ? 1 : INF));
                qtd_steps += mmax;
            }
        }
        ok |= (qtd_steps+1 >= dmin && dmin != INF);
        cout << (ok ? "YES" : "NO") << "\n"; 
    }
    return 0;
}
