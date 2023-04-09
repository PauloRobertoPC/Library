#include <bits/stdc++.h>

using namespace std;

#define INF int(1e9)

int h, w;
int M[41][41], DIST[41][41];
vector<pair<int, int>> adj[41][41];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool ok(int i, int j){
    return i >= 1 && i <= h && j >= 1 && j <= w;
}

void calc_adj(int a, int b){
    // cout << M[a][b] << ":\n";
    for(int i = 1; i <= h; i++)
        for(int j = 1; j <= w; j++)
            adj[i][j].clear();
    int aux = M[a][b];
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(i == a && j == b) continue;
            int gi = -1, gj = -1, mmin = INF;
            for(int k = 0; k < 4; k++){
                int ni = i+dx[k], nj = j+dy[k];
                if(!ok(ni, nj)) continue;
                if(abs(aux-M[ni][nj]) <= mmin){
                    if(mmin == (abs(aux-M[ni][nj]))){
                        //gi, gj ou ni nj  
                        if(abs(M[i][j]-M[ni][nj]) < abs(M[i][j]-M[gi][gj]))
                            gi = ni, gj = nj;
                        continue;
                    }
                    mmin = abs(aux-M[ni][nj]);
                    gi = ni, gj = nj;
                }
            }
            if(mmin == INF) continue;
            adj[gi][gj].emplace_back(i, j);
            // cout << M[gi][gj] << " -> " << M[i][j] << "\n";
        }
    }
    // cout << "\n";
}

void bfs(int i, int j){
    vector<vector<int>> dist(h+1, vector<int>(w+1, INF)); dist[i][j] = 0;
    queue<pair<int, int>> q; q.emplace(i, j);
    while(!q.empty()){
        tie(i, j) = q.front(); q.pop();
        for(auto [ni, nj]:adj[i][j]){
            if(dist[ni][nj] == INF){
                q.emplace(ni, nj);
                dist[ni][nj] = 1 + dist[i][j];
            }
        }
    }
    for(int i = 1; i <= h; i++)
        for(int j = 1; j <= w; j++)
            DIST[i][j] = max(DIST[i][j], dist[i][j]);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> h >> w; 
    for(int i = 1; i <= h; i++)
        for(int j = 1; j <= w; j++)
            cin >> M[i][j], DIST[i][j] = -1;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            calc_adj(i, j); 
            bfs(i, j);
        }
    }
    int ai = -1, aj = -1, mmin = INF;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(DIST[i][j] < mmin){
                mmin = DIST[i][j];
                ai = i;
                aj = j;
            }
        }
    }
    if(mmin == INF)
        cout << "impossible\n";
    else
        cout << M[ai][aj] << " " << DIST[ai][aj] << "\n";
    return 0; 
}
