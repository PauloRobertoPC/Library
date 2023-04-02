#include <bits/stdc++.h>

using namespace std;

struct DSU{
    vector<int> dad, _rank;

    DSU(int n){
        dad.resize(n+1);
        iota(dad.begin(), dad.end(), 0);
        _rank.assign(n+1, 1);
    }

    int find(int u){
        return dad[u] == u ? u : dad[u] = find(dad[u]);
    }

    void join(int u, int v){
        u = find(u), v = find(v);
        if(u != v){
            if(_rank[u] < _rank[v]) swap(u, v);
            dad[v] = u;
            _rank[u] += _rank[v];
        }
    }
};

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        string s, t; cin >> s >> t;
        DSU dsu(n);
        for(int i = 0; i < n; i++){
            if(i+k < n) dsu.join(i, i+k);
            if(i+k+1 < n) dsu.join(i, i+k+1);
        }
        map<int, string> mp1, mp2;
        for(int i = 0; i < n; i++){
            mp1[dsu.find(i)].push_back(s[i]);
            mp2[dsu.find(i)].push_back(t[i]);
        }
        for(auto &par:mp1) sort(par.second.begin(), par.second.end());
        for(auto &par:mp2) sort(par.second.begin(), par.second.end());
        bool ok = true;
        for(auto par:mp1) ok &= (par.second == mp2[par.first]);
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
