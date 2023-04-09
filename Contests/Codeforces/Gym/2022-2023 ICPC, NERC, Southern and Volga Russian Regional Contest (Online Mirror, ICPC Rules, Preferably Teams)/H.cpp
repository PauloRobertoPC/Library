#include <bits/stdc++.h>

using namespace std;

#define maxn int(2e3+10)

int n, m;
int p[maxn];
int a[maxn], b[maxn];
int ans[maxn];
vector<int> adj[maxn];

int calc(vector<int> dg, int s){
    priority_queue<pair<int, int>> pq;
    for(int i = 1; i <= n; i++) if(!dg[i] && i != s) pq.emplace(p[i], i);

    int pi, u, mmin = -1;
    for(int i = n; i >= 1; i--){
        if(pq.empty() || i > pq.top().first){
            if(!dg[s] && i <= p[s]) 
                mmin = i;
            break;
        }
        int u = pq.top().second; pq.pop();
        for(int v:adj[u]){
            --dg[v];
            if(!dg[v] && v != s)
                pq.emplace(p[v], v);
        }
    }
    return mmin;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m; 
    for(int i = 1; i <= n; i++) cin >> p[i];
    vector<int> dg(n+1);
    for(int i = 1; i <= m; i++){
        cin >> a[i] >> b[i];
        adj[b[i]].emplace_back(a[i]);
        ++dg[a[i]];
    }

    for(int i = 1; i <= n; i++) ans[i] = calc(dg, i);

    for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << "\n";
}
