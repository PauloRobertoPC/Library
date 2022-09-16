// DSU normal
struct DSU{
    vector<int> id, rnk;

    DSU(int n) : id(n), rnk(n, 1){ iota(id.begin(), id.end(), 0); } 

    int find(int x){ return id[x] == x ? x : id[x] = find(id[x]); } 

    void join(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return;
        if(rnk[x] < rnk[y]) swap(x, y);
        id[y] = x;
        rnk[x] += (rnk[x] == rnk[y]);
    }
};
