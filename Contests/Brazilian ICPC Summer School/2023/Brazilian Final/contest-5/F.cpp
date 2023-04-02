#include <bits/stdc++.h>

using namespace std;

#define INF int(1e7)

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

int xs, ys;
int xd, yd;
int B;
int C0;
int T, cost[110];
int N;
ii pos[1010];
vector<ii> to[1010];
vector<iii> adj[1010];

int calc_dist(int i, int j){
    int xx = pos[i].first - pos[j].first;
    int yy = pos[i].second - pos[j].second;
    return ceil(sqrt(xx*xx + yy*yy));
}

int dijkstra(int s = 0){
    vector<vector<int>> dist(N+10, vector<int>(B+1, INF));
    dist[s][0] = 0;
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.emplace(0, 0, s);
    while(!pq.empty()){
        int c, d, u; tie(c, d, u) = pq.top(); pq.pop();  
        if(c > dist[u][d]) continue;
        for(auto [v, c2, d2]:adj[u]){
            if(d+d2 <= B && dist[u][d]+c2 < dist[v][d+d2]){
                dist[v][d+d2] = dist[u][d]+c2;
                pq.emplace(dist[v][d+d2], d+d2, v);
            }
        }
    }
    int answ = INF;
    for(int i = 0; i <= B; i++) answ = min(answ, dist[N+1][i]);
    return answ;
}

int main(){
    cin >> xs >> ys;
    cin >> xd >> yd;
    cin >> B;
    cin >> C0;
    cin >> T;
    for(int i = 1; i <= T; i++) cin >> cost[i];
    cin >> N;
    for(int i = 1; i <= N; i++){
        int x, y;
        cin >> x >> y;
        pos[i] = {x, y};
        int l; cin >> l;
        while(l--){
            int station, mode; cin >> station >>  mode;
            to[i].emplace_back(station+1, mode);
        }
    }
    pos[0] = {xs, ys};
    pos[N+1] = {xd, yd};
    for(int i = 1; i <= N+1; i++){
        int d = calc_dist(0, i);
        adj[0].emplace_back(i, d*C0, d); 
        adj[i].emplace_back(0, d*C0, d); 
    }
    for(int i = 1; i <= N; i++){
        int d = calc_dist(N+1, i);
        adj[N+1].emplace_back(i, d*C0, d); 
        adj[i].emplace_back(N+1, d*C0, d); 
    }
    for(int i = 1; i <= N; i++){
        for(auto [station, mode]:to[i]){
            int d = calc_dist(i, station);
            adj[i].emplace_back(station, d*cost[mode], d);
            adj[station].emplace_back(i, d*cost[mode], d);
        }
    }
    int answ = dijkstra();
    cout << (answ == INF ? -1 : answ) << "\n";
    return 0;
}
// Description - Graph - Multiparameter Dijkstra
