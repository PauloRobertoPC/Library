#include <bits/stdc++.h>

using namespace std;

int n, m, color;
vector<string> M;
vector<vector<int>> C;
vector<vector<pair<int, int>>> config;
int dx[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[8] = {0, 0, 1, -1, 1, 1, -1, -1};

bool in(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m;
}

bool ok(int i, int j, int k){
    for(int o = 0; o < 2; o++){
        int ni = i + config[k][o].first;
        int nj = j + config[k][o].second;
        if(in(ni, nj) == false || M[ni][nj] == '.' || C[ni][nj] != -1) return false;
    }
    C[i][j] = color;
    for(int o = 0; o < 2; o++){
        int ni = i + config[k][o].first;
        int nj = j + config[k][o].second;
        C[ni][nj] = color;
    }
    return true;
}

int main(){
    config.push_back({{1, 0}, {1, -1}});
    config.push_back({{1, 0}, {1, 1}});
    config.push_back({{1, 0}, {0, 1}});
    config.push_back({{1, 1}, {0, 1}});
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        M.assign(n, "");
        C.assign(n, vector<int>(m, -1));
        bool ans = true;
        for(string &s:M) cin >> s;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(M[i][j] == '*' && C[i][j] == -1){
                    bool entrou = false;
                    for(int k = 0; k < 4;  k++){
                        if(ok(i, j, k)){
                            entrou = true;
                            break;
                        }
                    }
                    ans &= entrou;
                    ++color;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(M[i][j] == '*'){
                    for(int k = 0; k < 8;  k++){
                        int ni = i+dx[k];
                        int nj = j+dy[k];
                        if(in(ni, nj) && M[ni][nj] == '*' && C[ni][nj] != C[i][j])
                            ans = false;
                    }
                }
            }
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}
