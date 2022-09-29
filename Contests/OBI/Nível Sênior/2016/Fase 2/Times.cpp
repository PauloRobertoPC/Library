#include <bits/stdc++.h>

using namespace std;

#define maxn int(1e5+10)

int n;
int lvl[maxn];
vector<int> adj[maxn];

void dfs(int u, int h){
    lvl[u] = h; 
    for(int v:adj[u])
        if(!lvl[v])
            dfs(v, h+1);
}

int main(){
    cin >> n; 
    for(int i = 1; i <= n; i++){
        int tot; cin >> tot;
        while(tot--){
            int num; cin >> num;
            adj[i].emplace_back(num);
        }
    }
    for(int i = 1; i <= n; i++)
        if(!lvl[i])
            dfs(i, 1);
    vector<int> a, b;
    for(int i = 1; i <= n; i++){
        if(lvl[i]&1) a.emplace_back(i);
        else b.emplace_back(i);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(auto x:a) cout << x << " "; cout << "\n";
    for(auto x:b) cout << x << " "; cout << "\n";
    return 0;
}
