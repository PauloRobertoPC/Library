#include <bits/stdc++.h>

using namespace std;

#define INF int(1e9)

int n, m;
int dx[2] = {1, 0};
int dy[2] = {0, 1};
unordered_map<int, vector<pair<int, int>>> shots;

bool ok(int i, int j, int sec){
    bool b1 = i >= 0 && i <= n && j >= 0 && j <= m;
    if(!b1) return false;
    for(auto [d, coord]:shots[sec]){
        if(d == 1 && i == coord) return false;
        else if(d == 2 && j == coord) return false;
    }
    return true;
}

int BFS(){
    int MAX_JUMP = 110;
    vector<vector<vector<int>>> dist(n+1, vector<vector<int>>(m+1, vector<int>(MAX_JUMP, INF)));
    dist[0][0][0] = 0;
    queue<tuple<int, int, int>> q; q.emplace(0, 0, 0);
    while(!q.empty()){
        int i, j, p, ni, nj, sec; tie(i, j, p) = q.front(); q.pop();
        // cout << i << " " << j << " " << p << "\n";
        if(i == n && j == m) return dist[i][j][p];
        for(int k = 0; k < 2; k++){
            ni = i+dx[k], nj = j+dy[k], sec = dist[i][j][p]+1;
            if(ok(ni, nj, sec) && dist[ni][nj][p] == INF){
                dist[ni][nj][p] = sec;
                q.emplace(ni, nj, p);
            }
        }
        if(p < MAX_JUMP-1){
            sec = dist[i][j][p]+1;
            if(ok(i, j, sec) && dist[i][j][p+1] == INF){
                dist[i][j][p+1] = sec;
                q.emplace(i, j, p+1);
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        int r; cin >> r;
        while(r--){
            int sec, d, coord;
            cin >> sec >> d >> coord;
            shots[sec].emplace_back(d, coord);
        }
        int ans = BFS();
        cout << ans << "\n";
        shots.clear();
    }
    return 0;
}
