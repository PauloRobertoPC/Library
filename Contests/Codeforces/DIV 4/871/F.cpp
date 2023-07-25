#include <bits/stdc++.h>

using namespace std;


int main(){
    int t; cin >> t;
    while(t--){
        int n, m; 
        cin >> n >> m;
        vector<vector<int>> adj(n+1, vector<int>());
        while(m--){
            int u, v; cin >> u >> v;
            adj[u].emplace_back(v); 
            adj[v].emplace_back(u); 
        }
        vector<int> mark(n+1, -1);
        for(int i = 1; i <= n; i++){
            if(adj[i].size() == 1)
                mark[i] = 1;
        }
        for(int i = 1; i <= n; i++)
            if(mark[i] == -1)
                for(int v:adj[i])
                    if(mark[v] == 1)
                        mark[i] = 2;
        for(int i = 1; i <= n; i++){
            if(mark[i] == -1)
                cout << adj[i].size() << " ";
        }
        for(int i = 1; i <= n; i++){
            if(mark[i] == 2){
                cout << adj[i].size()-1 << "\n";
                break;
            }
        }
    }
    return 0;
}
