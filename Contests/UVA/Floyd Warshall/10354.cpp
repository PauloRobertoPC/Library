#include <bits/stdc++.h>

using namespace std;

#define INF int(1e8)

typedef vector<vector<int>> Matrix;

Matrix fw(Matrix M, vector<int> &closed){
    int n = M.size();
    for(int k = 1; k < n; k++){
        if(closed[k]) continue;
        for(int i = 1; i < n; i++){
            if(closed[i]) continue;
            for(int j = 1; j < n; j++){
                if(closed[j]) continue;
                M[i][j] = min(M[i][j], M[i][k]+M[k][j]);
            }
        }
    }
    return M;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b, c, d;
    while(cin >> n >> m >> a >> b >> c >> d){
        Matrix M(n+1, vector<int>(n+1, INF));
        for(int i = 1; i <= n; i++) M[i][i] = 0;
        int u, v, w;
        while(m--){
            cin >> u >> v >> w;
            M[u][v] = min(M[u][v], w);
            M[v][u] = min(M[v][u], w);
        }
        vector<int> closed(n+1, 0);
        Matrix M1 = fw(M, closed);
        for(int i = 1; i <= n; i++)
            if(M1[a][b] == M1[a][i] + M1[i][b])
                closed[i] = 1;
        M1 = fw(M, closed);
        if(M1[c][d] == INF || closed[c] || closed[d])
            cout << "MISSION IMPOSSIBLE.\n";
        else
            cout << M1[c][d] << "\n";
    }
    return 0;
}
