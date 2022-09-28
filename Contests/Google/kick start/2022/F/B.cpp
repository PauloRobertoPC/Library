#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> graph;

struct BIT{
    int maxn;
    vector<int> bit;
    
    BIT(int n) : bit(n+1, 0), maxn(n+10){}

    void update(int pos, int val){
        for(; pos < maxn; pos += (pos&(-pos))) bit[pos] += val;
    }

    int sum(int pos){
        int ans = 0;
        for(; pos > 0; pos -= (pos&(-pos))) ans += bit[pos];
        return ans;
    }
};

void solve(){
    int q, n; cin >> n >> q;
    graph adj(n+1);
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    int lvlmax = 1;
    vector<int> lvl(n+1), qtd(n+1, 0); lvl[1] = 1; qtd[1] = 1;
    queue<pair<int, int>> f; f.push({1, -1});
    while(!f.empty()){
        int u, p; tie(u, p) = f.front(); f.pop();
        for(int v:adj[u]){
            if(v != p){
                lvl[v] = lvl[u] + 1;
                ++qtd[lvl[v]];
                lvlmax = max(lvlmax, lvl[v]);
                f.push({v, u});
            }
        }
    }
    for(int i = 1; i <= n; i++) qtd[i] += qtd[i-1];
    // for(int i = 1; i <= n; i++) cout << qtd[i] << " "; cout << "\n";
    BIT bit(n);
    while(q--){
        int i; cin >> i;
        bit.update(lvl[i], 1); 
    }
    // for(int i = 1; i <= n; i++) cout << bit.sum(i) << " "; cout << "\n";
    // for(int i = 1; i <= n; i++) cout << qtd[i] << " "; cout << "\n";
    int tot = bit.sum(n), ans = 0;
    for(int i = 0; i <= lvlmax; i++)
        if(qtd[i] <= tot) ans = qtd[i];
    cout << ans << "\n";
}

int main(){
    int t; cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
