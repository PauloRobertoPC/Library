#include <bits/stdc++.h>
#include <iomanip>
#include <ios>

using namespace std;

typedef long double ld;

ld ans;
vector<pair<int, ld>> adj[110];

void dfs(int u, int p, int ut, ld prod){
    if(u == ut) ans = prod;
    for(auto [v, cv]:adj[u])
        if(v != p)
            dfs(v, u, ut, prod*cv);
}

int main(){
    int n, q; cin >> n >> q;
    map<string, int> ids; int id = 0;
    for(int i = 0; i < n; i++){
        ld a, b; string s1, s2, s3;
        cin >> a >> s1 >> s2 >> b >> s3;
        if(!ids.count(s1)) ids[s1] = id++;
        if(!ids.count(s3)) ids[s3] = id++;
        adj[ids[s1]].emplace_back(ids[s3], (1.0*b)/(1.0*a));
        adj[ids[s3]].emplace_back(ids[s1], (1.0*a)/(1.0*b));
        // cout << a << " " << s1 << " " << s2 << " " << b << " " << s3 << "\n";
    }
    cout << scientific << setprecision(53);
    while(q--){
        ld m; string s1, s2, s3;
        cin >> m >> s1 >> s2 >> s3;
        ans  = -1;
        dfs(ids[s1], ids[s1], ids[s3], m);
        if(ans == -1){
            cout << "impossible\n";
        }else{
            cout << ans << "\n";
        }
    }
    return 0;
}
