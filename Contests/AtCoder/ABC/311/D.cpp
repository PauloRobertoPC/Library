#include <bits/stdc++.h>

using namespace std;

#define maxn 210

int n, m;
int vis[maxn][maxn][5];
string M[210];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int i, int j, int dir = 4){
    vis[i][j][dir] = 1;
    if(dir == 4){
        for(int k = 0; k < 4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(M[ni][nj] == '.' && !vis[ni][nj][k]){
                dfs(ni, nj, k);
            }
        }
    }else{
        int ni = i + dx[dir];
        int nj = j + dy[dir];
        if(M[ni][nj] == '#') dfs(i, j, 4);
        else dfs(ni, nj, dir);
    }

}

int main(){
    cin >> n >> m;
    M[0] = string('#', m+10);
    for(int i = 1; i <= n; i++){ 
        string s, t; cin >> s; t = '#'; t += s;
        M[i] = t;
    }
    int ans = 0;
    dfs(2, 2);
    for(int i = 1; i < maxn; i++){
        for(int j = 1; j < maxn; j++){
            bool add = false;
            for(int k = 0; k < 5; k++){
                add |= vis[i][j][k];
            }
            ans += add;
        }
    }
    cout << ans << "\n";
    return 0;
}
