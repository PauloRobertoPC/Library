#include <bits/stdc++.h>

using namespace std;

int n, cc;
int CC[11][11];
char M[11][11];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<pair<int, int>> use;
vector<set<pair<int, int>>> free_pos;

int in(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < n;
}

void dfs(int i, int j){
    CC[i][j] = cc; 
    for(int k = 0; k < 4; k++){
        int ni = i + dx[k], nj = j + dy[k];
        if(in(ni, nj) && M[ni][nj] == '*' && !CC[ni][nj])
            dfs(ni, nj);
    }
}

map<set<pair<int, int>>, int> vis;

int grundy(set<pair<int, int>> pos){
    if(pos.empty()) return 0;
    if(vis.count(pos)) return vis[pos];
    set<int> mex;
    for(auto [i, j]:pos){
        set<pair<int, int>> npos = pos;
        npos.erase({i, j});
        for(int k = 0; k < 4; k++){
            int ni = i + dx[k], nj = j + dy[k];
            if(in(ni, nj))
                npos.erase({ni, nj});
        }
        mex.insert(grundy(npos));
    }
    int mx = 0;
    for(int x:mex){
        if(x != mx) break;
        ++mx;
    }
    vis[pos] = mx;
    return mx;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> M[i][j];
    cc = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(M[i][j] == '*' && !CC[i][j])
                dfs(i, j), ++cc;

    free_pos.assign(cc, set<pair<int, int>>());
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(CC[i][j] != 0){
                for(int k = 0; k < 4; k++){
                    int ni = i + dx[k], nj = j + dy[k];
                    if(in(ni, nj) && M[ni][nj] == '.' && !CC[ni][nj])
                        free_pos[CC[i][j]].insert({ni, nj}); 
                }
            }
        }
    }

    int xr = 0;
    for(int i = 1; i < cc; i++){
        for(auto par: free_pos[i]) use.emplace_back(par);  
        xr ^= grundy(free_pos[i]);
    }
    cout << (xr ? "First player will win" : "Second player will win") << "\n";
    return 0;
}
