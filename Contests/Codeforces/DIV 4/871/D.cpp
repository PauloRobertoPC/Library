#include <bits/stdc++.h>

using namespace std;

#define maxn int(1e7+10)

bool BFS(int n, int m){
    unordered_map<int, int> vis;
    queue<int> q; q.emplace(n); vis[n] = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        // cout << u << "\n";
        if(u == m) return true;
        if(u%3 == 0){
            int a = 2*u/3;
            int b = u/3;
            if(!vis[a]) q.emplace(a), vis[a] = 1;
            if(!vis[b]) q.emplace(b), vis[b] = 1;
        }
    }
    return false;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        bool ok = false;
        if(n >= m && BFS(n, m)) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}
