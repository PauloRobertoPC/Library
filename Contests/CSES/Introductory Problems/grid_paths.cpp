#include <bits/stdc++.h>
#include <vector>

using namespace std;

typedef long long ll;

string s, op = "DURL";
vector<vector<int>> vis;
vector<array<int, 2>> d;

int solve(int pos, int i, int j){
    if(vis[i][j+1] && vis[i][j-1] && !vis[i+1][j] && !vis[i-1][j]) return 0;
    if(vis[i+1][j] && vis[i-1][j] && !vis[i][j+1] && !vis[i][j-1]) return 0;
    if(i == 7 && j == 1) return (pos == s.size());
    if(pos == s.size()) return 0;

    int tot = 0;
    vis[i][j] = 1;
    if(s[pos] != '?'){
        int ni = i+d[s[pos]][0], nj = j+d[s[pos]][1];
        if(!vis[ni][nj])
            tot += solve(pos+1, ni, nj);
    }else{
        for(int k = 0; k < 4; k++){
            int ni = i+d[op[k]][0], nj = j+d[op[k]][1];
            if(!vis[ni][nj])
                tot += solve(pos+1, ni, nj);
        }
    }
    vis[i][j] = 0;
    return tot;
}

int main(){
    cin >> s;
    d.resize(256);
    d['D'] = {1, 0};
    d['U'] = {-1, 0};
    d['R'] = {0, 1};
    d['L'] = {0, -1};
    vis.assign(10, vector<int>(10, 1));
    for(int i = 1; i <= 7; i++)
        for(int j = 1; j <= 7; j++)
            vis[i][j] = 0;
    cout << solve(0, 1, 1) << "\n";
    return 0;
}
