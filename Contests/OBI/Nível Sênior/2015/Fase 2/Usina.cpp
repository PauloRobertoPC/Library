#include <bits/stdc++.h>

using namespace std;

#define maxn int(1e5+10)
#define INF int(1e9+100)

int n, m, c, k;
int visited[maxn];
vector<int> salas_com_pessoa;
vector<pair<int, int>> adj[maxn];

vector<int> dijkstra(int s){
    vector<int> dist(n+1, INF); dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dist[s], s});
    int u, d;
    while(!pq.empty()){
        tie(d, u) = pq.top(); pq.pop();
        if(d > dist[u]) continue;
        for(auto [v, w]:adj[u]){
            if(dist[u]+w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> c >> k;
    for(int i = 0; i < c; i++){
        int pessoa;
        cin >> pessoa;
        salas_com_pessoa.emplace_back(pessoa);
    }
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    
    vector<tuple<int, int, int>> arestas; 
    for(int i:salas_com_pessoa){
        vector<int> dist = dijkstra(i);
        for(int j:salas_com_pessoa){
            if(i == j || dist[j] == INF) continue;
            arestas.emplace_back(i, j, max(0, dist[j]-k));
        }
    }

    for(auto [u, v, w]:arestas)
        adj[u].emplace_back(v, w);
    
    vector<int> dist = dijkstra(1);
    cout << (dist[n] == INF ? -1 : dist[n]) << "\n";
    return 0;
}
