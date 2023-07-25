#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> M;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool in(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m;
}

void BFS(vector<pair<int, int>> &source, int p, int &ans){
    vector<vector<int>> dist(n, vector<int>(m, -1)); 
    queue<pair<int, int>> q;
    for(auto [i, j]:source){
        dist[i][j] = 0;
        q.emplace(i, j);
    }
    while(!q.empty()){
        int i, j; tie(i, j) = q.front(); q.pop();
        for(int k = 0; k < 4; k++){
            int ni = i + dx[k], nj = j + dy[k];
            if(in(ni, nj) && dist[ni][nj] == -1){
                dist[ni][nj] = dist[i][j]+1;
                q.emplace(ni, nj); 
            }
        }
    }
    int mmin = n*m+10;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(M[i][j] == p && dist[i][j] <= mmin){
                if(dist[i][j] < mmin) source.clear();
                mmin = dist[i][j];
                source.emplace_back(i, j);
            }
        }
    }
    ans += mmin;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    M.assign(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> M[i][j];
    vector<pair<int, int>> source;
    source.emplace_back(0, 0);
    int ans = 0;
    int q; cin >> q;
    while(q--){
        int p;
        cin >> p;
        BFS(source, p, ans);
    }
    cout << ans << "\n";
    return 0;
}
