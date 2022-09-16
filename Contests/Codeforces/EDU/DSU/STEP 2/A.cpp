#include <bits/stdc++.h>

using namespace std;

struct DSU{
    vector<int> id, rnk, mmax;

    DSU(int n) : id(n), rnk(n, 1), mmax(n){ 
        iota(id.begin(), id.end(), 0); 
        iota(mmax.begin(), mmax.end(), 0); 
    } 

    int find(int x){ return id[x] == x ? x : id[x] = find(id[x]); } 

    void join(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return;
        if(rnk[x] < rnk[y]) swap(x, y);
        mmax[x] = max(mmax[x], mmax[y]);
        id[y] = x;
        rnk[x] += (rnk[x] == rnk[y]);
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> rm(n+1, 0);
    DSU dsu(n+1);
    while(m--){
        char op; int id; cin >> op >> id; 
        if(op == '?'){
            id = dsu.find(id);
            id = dsu.mmax[id];
            cout << (id == n && rm[id] ? -1 : id) << "\n";
        }else{
            rm[id] = 1;
            if(id != n) dsu.join(id, id+1);
        }
    }
    return 0;
}
