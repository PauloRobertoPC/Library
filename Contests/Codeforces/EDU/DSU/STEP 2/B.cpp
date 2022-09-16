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
    int n; cin >> n;
    vector<bool> used(n+1, 0);
    DSU dsu(n+1);
    for(int i = 0; i < n; i++){
        int slot; cin >> slot;        
        int id = dsu.find(slot);
        int mmax = dsu.mmax[id];
        if(mmax == n && used[n]){
            id = dsu.find(1);
            mmax = dsu.mmax[id];
        }
        if(mmax != n) dsu.join(mmax, mmax+1); 
        used[mmax] = 1;
        cout << mmax << " ";
    }
    cout << "\n";
    return 0;
}
