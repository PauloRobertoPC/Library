#include <bits/stdc++.h>

using namespace std;

int r, c;
int M[110][110], ja[110][110];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool ok(int i, int j){
    return i >= 0 && i < r && j >= 0 && j < c;
}

int BFS(pair<int, int> s){
    int tot = 0;
    vector<vector<int>> vis(r, vector<int>(c, 0)); vis[s.first][s.second] = 1;
    priority_queue<tuple<int, int, int>> pq; pq.emplace(-M[s.first][s.second], s.first, s.second);
    while(!pq.empty()){
        int w, i, j; tie(w, i, j) = pq.top(), pq.pop();
        ja[i][j] = 1;
        ++tot;
        for(int k = 0; k < 4; k++){
            int ni = i + dx[k], nj = j + dy[k];
            if(ok(ni, nj) && !vis[ni][nj] && M[ni][nj] > M[i][j]){
                pq.emplace(-M[ni][nj], ni, nj);
                vis[ni][nj] = 1;
            }
        }
    }
    return tot;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> r >> c;
    vector<pair<int, int>> pos(r*c+1);
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> M[i][j],
            pos[M[i][j]] = {i, j};
    int ans = -1;
    for(int i = 1; i <= r*c; i++)
        if(!ja[pos[i].first][pos[i].second])
            ans = max(ans, BFS(pos[i]));
    cout << ans << "\n"; 
    return 0;
}
