#include <bits/stdc++.h>

using namespace std;

int n;
char M[3][110];
int vis[3][110];
int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, -1, 1, 1, -1, -1, 1};

bool ok(int i, int j){
    return i >= 1 && i <= 2 && j >= 1 && j <= n;
}

void dfs(int i, int j){
    vis[i][j] = 1;
    for(int k = 0; k < 8; k++){
        int ni = i+dx[k], nj = j+dy[k];
        if(ok(ni, nj) && !vis[ni][nj] && M[ni][nj] == '0')
            dfs(ni, nj);
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= 2; i++)
        for(int j = 1; j <= n; j++)
            cin >> M[i][j];
    dfs(1, 1);
    cout << (vis[2][n] ? "YES" : "NO") << "\n";
    return 0;
}
