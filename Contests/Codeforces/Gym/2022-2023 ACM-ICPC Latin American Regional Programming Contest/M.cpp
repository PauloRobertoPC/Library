#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<string> M;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool ok(string &p, int v, int sft){
    for(int i = 0; i < m; i++)
        if(p[(i+sft)%m] == '1' && M[v][i] == '1')
            return false;
    return true;
}

bool BFS(string p){
    vector<vector<int>> vis(n+2, vector<int>(m, 0)); vis[0][0] = 1;
    queue<tuple<int, int>> q; q.emplace(0, 0);
    while(!q.empty()){
        int v, sft; tie(v, sft) = q.front(); q.pop();
        if(v == n+1) return true;
        for(int k = 0; k < 4; k++){
            int v2 = v + dx[k], sft2 = (sft+dy[k]+m)%m;
            if(v2 >= 0 && !vis[v2][sft2] && ok(p, v2, sft2)){
                vis[v2][sft2] = 1;
                q.emplace(v2, sft2);
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    string s; cin >> s;
    string s2 = "";
    for(int i = s.size()-1; i >= 0; i--) s2.push_back(s[i]);
    M.resize(n+2); M[0] = M[n+1] = string(m, '0');
    for(int i = 1; i <= n; i++) cin >> M[i];
    cout << (BFS(s) || BFS(s2) ? 'Y' : 'N') << "\n";
    return 0;
}
