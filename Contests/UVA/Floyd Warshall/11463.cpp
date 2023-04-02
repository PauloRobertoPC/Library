#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, c = 1; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<vector<int>> M(n, vector<int>(n, int(1e8)));
        for(int i = 0; i < n; i++) M[i][i] = 0;
        while(m--){
            int u, v; cin >> u >> v;
            M[u][v] = M[v][u] = 1;
        }
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    M[i][j] = min(M[i][j], M[i][k]+M[k][j]);
        int s, d; cin >> s >> d;
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans, M[s][i] + M[i][d]);
        cout << "Case " << c++ << ": " << ans << "\n";
    }
    return 0;
}
