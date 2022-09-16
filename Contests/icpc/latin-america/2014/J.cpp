#include <bits/stdc++.h>
#include <cinttypes>

using namespace std;

#define INF int(1e8)

int n, cnt;
int vis[110][110];
char M[110][110];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool in(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < n;
}

bool ok(int i, int j, int mask){
    if(int(M[i][j])>= 'a'){  //Minúscula
        int d = int(M[i][j]-'a'); 
        return ((mask&(1<<d)) == 0);
    }else{             //Maiúscula
        int d = int(M[i][j]-'A'); 
        return ((mask&(1<<d)) != 0);
    }
    return true;
}

int bfs(int mask){
    queue<tuple<int, int, int>> q;
    q.push({1, 0, 0});
    int d, i, j;
    while(!q.empty()){
        tie(d, i, j) = q.front(); q.pop();
        // cout << i << " " << j << "\n";
        if(i == n-1 && j == n-1) return d;
        for(int k = 0; k < 4; k++){
            int ni = i+dx[k], nj = j+dy[k];
            if(in(ni, nj) && ok(ni, nj, mask) && vis[ni][nj] < cnt){
                q.push({d+1, ni, nj});
                vis[ni][nj] = cnt;
            }
        }
    }
    ++cnt; 
    return INF;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> M[i][j];
    cnt = 1;
    int ans = INF;
    char ca = M[0][0], cb = M[n-1][n-1]; 
    int mask = 0;
    int da = (ca >= 'a' ? int(ca-'a') : int(ca-'A'));
    int db = (cb >= 'a' ? int(cb-'a') : int(cb-'A'));
    mask |= ((ca < 'a')<<da);
    mask |= ((cb < 'a')<<db);
    int lim = (1<<10);
    for(int i = 0; i < lim; i++){
        if((i&(1<<da)) != (mask&(1<<da)) || (i&(1<<db)) != ((mask&(1<<db)))) continue;
        ans = min(ans, bfs(i));
    }
    cout << (ans == INF ? -1 : ans) << "\n";
    return 0;
}
