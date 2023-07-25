#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> M;
vector<vector<int>> vis;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool in(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < m;
}

int dfs(int i, int j){
    vis[i][j] = 1; 
    int ans = M[i][j];
    for(int k = 0; k < 4; k++){
        int ni = i+dx[k], nj = j+dy[k];
        if(in(ni, nj) && !vis[ni][nj] && M[ni][nj])
            ans += dfs(ni, nj);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        M.assign(n, vector<int>(m));
        vis.assign(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> M[i][j];
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(M[i][j] && !vis[i][j])
                    ans = max(ans, dfs(i, j));
        cout << ans << "\n";
    }
    return 0;
}
