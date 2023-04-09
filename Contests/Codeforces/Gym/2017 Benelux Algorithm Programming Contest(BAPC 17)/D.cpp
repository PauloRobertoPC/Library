#include <bits/stdc++.h>

using namespace std;

#define INF ll(1e18)

typedef long long ll;
typedef vector<vector<tuple<ll,ll>>> Graph;

vector<ll> dijkstra(Graph &adj, ll s, ll n){
    vector<ll> dist(n, INF), p(n, -1);
    priority_queue<tuple<ll, ll>> pq; pq.push({0, s}); dist[s] = 0;
    ll u, v, w, d;
    while(!pq.empty()){
        tie(d, u) = pq.top(); pq.pop();
        d = -d;
        if(d > dist[u]) continue;
        for(auto [v, w]:adj[u]){
            if(d+w < dist[v]){
                dist[v] = d+w;
                p[v] = u;
                pq.push({-dist[v], v});
            }
        }
    }
    return p;
}


int main(){
    ll n, m; cin >> n >> m;
    Graph adj1(n), adj2(n);
    vector<tuple<ll, ll, ll>> e;
    ll u, v, w;
    for(ll i = 0; i < m; i++){
        cin >> u >> v >> w;
        e.emplace_back(u, v, w);
        adj1[u].emplace_back(v, w);
        adj1[v].emplace_back(u, w);
    }
    vector<ll> dad = dijkstra(adj1, 1, n);
    set<tuple<ll, ll>> cj;
    for(ll i = 0; i < n; i++) cj.insert({i, dad[i]});
    for(auto [u, v, w]:e){
        if(!cj.count({u, v})) adj2[u].emplace_back(v, w);
        if(!cj.count({v, u})) adj2[v].emplace_back(u, w);
    }
    dad = dijkstra(adj2, 0, n);
    if(dad[1] == -1){
        cout << "impossible\n";
}else{
        v = 1;
        vector<ll> path;
        while(v != -1) path.emplace_back(v), v = dad[v];
        cout << path.size() << " ";
        for(ll i = path.size()-1; i >= 0; i--) cout << path[i] << " "; cout << "\n";
    }

}
