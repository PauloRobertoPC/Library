#include <bits/stdc++.h>

using namespace std;

#define INF ll(1e13)

typedef long long ll;

ll n, m, q;

vector<vector<ll>> fw(vector<vector<ll>> M){
    for(ll k = 0; k < n; k++)
        for(ll i = 0; i < n; i++)
            for(ll j = 0; j < n; j++)
                if(M[i][k] < INF && M[k][j] < INF)
                    M[i][j] = min(M[i][j], M[i][k]+M[k][j]);
     for(ll i = 0; i < n; i++) 
        for(ll j = 0; j < n; j++) 
            for(ll k = 0; k < n; k++) 
                if(M[k][k] < 0 && M[i][k] != INF && M[k][j] != INF) 
                    M[i][j] = -INF;
    return M;
}

int main(){
    while(cin >> n >> m >> q){
        if(n == 0 && m == 0 && q == 0) break;
        vector<vector<ll>> M(n, vector<ll>(n, INF));
        for(ll i = 0; i < n; i++) M[i][i] = 0;
        ll u, v, w;
        while(m--){
            cin >> u >> v >> w;
            M[u][v] = min(M[u][v], w);
        }
        vector<vector<ll>> M1 = fw(M);
        while(q--){
            ll u, v;
            cin >> u >> v;
            if(M1[u][v] == INF)
                cout << "Impossible\n";
            else if(M1[u][v] == -INF)
                cout << "-Infinity\n";
            else
                cout << M1[u][v] << "\n";
        }
        cout << "\n";
    }
    return 0;
}
