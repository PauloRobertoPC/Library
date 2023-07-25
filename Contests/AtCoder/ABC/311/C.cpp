#include <bits/stdc++.h>

using namespace std;

#define maxn int(2e5+10)

int a, b;
int dad[maxn], color[maxn];
vector<int> adj[maxn];

void dfs(int u){
    color[u] = 1;
    for(int v:adj[u]){
        if(color[v] == 0){
            dad[v] = u;
            dfs(v);
        }else if(color[v] == 1){
            a = u; b = v;
        }
    }
    color[u] = 2;
}

int main(){
    int n;
    cin >> n;
    for(int i = 1, v; i <= n; i++){
        cin >> v;
        adj[i].emplace_back(v);
    }
    for(int i = 1; i <= n; i++)
        if(color[i] == 0)
            dfs(i);
    vector<int> ans;
    while(a != b){
        ans.emplace_back(a);
        a = dad[a];
    }
    ans.emplace_back(b);
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++)
        cout << ans[ans.size()-1-i] << " ";
    cout << "\n";
    return 0;
}
