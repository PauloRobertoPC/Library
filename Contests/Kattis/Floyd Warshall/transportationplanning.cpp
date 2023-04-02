#include <bits/stdc++.h>
#include <iomanip>
#include <vector>

using namespace std;

#define INF 1e20

typedef long double ld;

ld dist(pair<int, int> &a, pair<int, int> &b){
    ld xx = a.first - b.first;
    ld yy = a.second - b.second;
    return sqrt(xx*xx + yy*yy);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin >> n, n){
        
        vector<pair<int, int>> P(n);
        for(auto &[x, y]:P) cin >> x >> y; 
        
        vector<vector<ld>> E(n, vector<ld>(n, 0));
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                E[i][j] = E[j][i] = dist(P[i], P[j]);
                
        vector<vector<ld>> M(n, vector<ld>(n, INF));
        for(int i = 0; i < n; i++) M[i][i] = 0; 
        vector<vector<bool>> used(n, vector<bool>(n, 0));
        int m; cin >> m;
        while(m--){
            int u, v; cin >> u >> v;
            used[u][v] = used[v][u] = 1;
            M[u][v] = M[v][u] = E[u][v];
        }

        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    M[i][j] = min(M[i][j], M[i][k]+M[k][j]);

        ld sum = 0;
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                if(M[i][j] != INF)
                    sum += M[i][j];

        ld mmin = sum; int v1, v2;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(used[i][j] || i == j) continue;
                ld including = 0;
                for(int u = 0; u < n; u++){
                    for(int v = u+1; v < n; v++){
                        ld aux = min({M[u][i]+E[i][j]+M[j][v], M[u][j]+E[j][i]+M[i][v], M[u][v]});
                        if(aux < INF)
                            including += aux;
                    }
                }
                if(including < mmin){
                    v1 = i, v2 = j;
                    mmin = including;
                }
            }
        }
        cout << fixed << setprecision(10);
        if(sum == mmin)
            cout << "no addition reduces " << sum << "\n"; 
        else
            cout << "adding " << v1 << " " << v2 << " reduces " << sum << " to " << mmin << "\n";
    }
    return 0;
}
