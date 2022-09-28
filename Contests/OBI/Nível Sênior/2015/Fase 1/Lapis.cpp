#include <bits/stdc++.h>

using namespace std;

#define maxn int(1e3+10)

int n;
int mat[maxn][maxn];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool in_grid(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < n;
}

void bfs(){
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++)
            if(!mat[i][j])
                q.push({i, j});
    int i, j, ni, nj;
    while(!q.empty()){
        tie(i, j) = q.front(); q.pop();
        for(int k = 0; k < 4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(in_grid(ni, nj) && mat[ni][nj] == maxn){
                mat[ni][nj] = min(mat[i][j]+1, 9);
                q.push({ni, nj});
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char ch;
            cin >> ch;
            mat[i][j] = (ch == '0' ? 0 : maxn);
        }
    }
    bfs();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << mat[i][j];
        }
        cout << "\n";
    }
    return 0;
}
