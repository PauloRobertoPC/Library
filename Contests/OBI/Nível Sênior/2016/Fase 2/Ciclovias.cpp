#include <bits/stdc++.h>

using namespace std;

#define maxn int(1e5+10)

int n, m;
int suf[maxn];
vector<int> adj[maxn];

int main(){
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<int> max_sequence(n+1, 1);
    for(int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
    for(int i = n; i >= 1; i--){
        suf[adj[i].size()] = 0; 
        for(int j = adj[i].size()-1; j >= 0; j--)
            suf[j] = max(max_sequence[adj[i][j]], suf[j+1]);
        for(int j = 0; j < adj[i].size(); j++){
            int u = adj[i][j];
            max_sequence[u] = max(2+suf[j+1], max_sequence[u]);
        }
    }

    for(int i = 1; i <= n; i++) cout << max_sequence[i] << " "; cout << "\n";
     
    return 0;
}
