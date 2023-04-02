#include <bits/stdc++.h>

using namespace std;

int n, m, d, si, sj, fi, fj;
vector<pair<int, int>> monsters;
vector<vector<char>> M;
vector<vector<int>> vis;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool ok(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m;
}

int BFS(bool monster){
    queue<pair<int, int>> q;
    if(monster){
        for(auto [i, j]:monsters) vis[i][j] = 0, q.emplace(i, j);
    }else if(M[si][sj] == '.'){
        M[si][sj] = 'x';
        vis[si][sj] = 0;
        q.emplace(si, sj);
    }
    while(!q.empty()){
        int i, j; tie(i, j) = q.front(); q.pop();
        if(monster && vis[i][j] == d) continue;
        for(int k = 0; k < 4; k++){
            int ni = i + dx[k], nj = j + dy[k];
            if(ok(ni, nj) && vis[ni][nj] == -1 && M[ni][nj] == '.'){
                M[ni][nj] = (monster ? 'M' : 'x');
                vis[ni][nj] = vis[i][j] + 1;
                q.emplace(ni, nj);
            }
        }
    }
    int ans = (!monster && M[si][sj] == 'x' && M[fi][fj] == 'x' ? vis[fi][fj] : -1);
    return ans;
}

int main(){
    cin >> n >> m >> d;
    M.assign(n, vector<char>(m));
    vis.assign(n, vector<int>(m, -1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> M[i][j];
            if(M[i][j] == 'S'){
                M[i][j] = '.';
                si = i;
                sj = j;
            }else if(M[i][j] == 'F'){
                M[i][j] = '.';
                fi = i;
                fj = j;
            }else if(M[i][j] == 'M'){
                monsters.emplace_back(i, j);
            }
        }
    }
    BFS(true);
    cout << BFS(false) << "\n";
    return 0;
}
//Description: Graph - BFS Multisource
