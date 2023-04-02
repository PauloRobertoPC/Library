#include <bits/stdc++.h>
#include <bitset>
#include <ios>

using namespace std;

typedef vector<vector<bool>> paint;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> tot(k+1);
    vector<paint> paints(k+1, paint(n, vector<bool>(m)));
    char ch;
    for(int c = 0; c <= k; c++){
        tot[c] = {0, c};
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> ch, paints[c][i][j] = (ch-'0');
    }

    for(int c = 0; c <= k; c++){
        for(int i = 1; i+1 < n; i++){
            for(int j = 1; j+1 < m; j++){
                bool can = true; 
                for(int o = 0; o < 4; o++){
                    int ni = i+dx[o], nj = j+dy[o];
                    if(paints[c][i][j] == paints[c][ni][nj]) can = false;
                }
                tot[c].first += can;
            }
        }
    }

    sort(tot.rbegin(), tot.rend());
    vector<tuple<int, int, int>> ans;
    for(int c = 0; c < k; c++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(paints[tot[c].second][i][j] != paints[tot[c+1].second][i][j]){
                    paints[tot[c].second][i][j] = paints[tot[c].second][i][j]^1;
                    ans.emplace_back(1, i+1, j+1);
                }
            }
        }
        ans.emplace_back(2, tot[c+1].second+1, -1);
    }
    
    cout << tot[0].second+1 << "\n";
    cout << ans.size() << "\n";
    for(auto [a, b, c]:ans){
        cout << a << " " << b;
        if(c != -1) cout << " " << c << "\n";
        else cout << "\n";
    }
    return 0;
}
