#include <bits/stdc++.h>

using namespace std;

struct SEG{
    struct no{
        int id, rnk, lazy;
        no(){ id = rnk = lazy= 0; }
        no(int id, int rnk) : id(id), rnk(rnk), lazy(0) {}
    };
    no neut;
    vector<int> v;
    vector<no> seg;

    SEG(int n, int *v) : seg(n<<2), v(n, 0) {}

    static no merge(no a, no b){
        no c;
        c.val = a.val+b.val;
        return c;
    }

    void build(int node, int l, int r){
        if(l == r){
            seg[node] = v[l];
            return;
        }
        int mid = (l+r)>>1, nxt = node<<1;
        build(nxt, l, mid);
        build(nxt+1, mid+1, r);
        seg[node] = merge(seg[nxt], seg[nxt+1]);
    }

    void push(int node, int l, int r){
        if(seg[node].lazy){
            seg[node].val += (r-l+1)*seg[node].lazy;
            if(l != r){
                int nxt = node<<1;
                seg[nxt].lazy += seg[node].lazy;
                seg[nxt+1].lazy += seg[node].lazy;
            }
            seg[node].lazy = 0;
        }
    }

    //val may not be a integer
    void update(int node, int l, int r, int x, int y, int val){
        push(node, l, r);
        if(l > y || r < x) return;
        if(l >= x && r <= y){
            seg[node].lazy += val;
            push(node, l, r);
            return;
        }
        int mid = (l+r)>>1, nxt = node<<1;
        update(nxt, l, mid, x, y, val);
        update(nxt+1, mid+1, r, x, y, val);
        seg[node] = merge(seg[nxt], seg[nxt+1]);
    }

    no neutral(){
        return neut;
    }

    no get(int node, int l, int r, int x, int y){
        push(node, l, r);
        if(l > y || r < x) return neutral();
        if(l >= x && r <= y) return seg[node];
        int mid = (l+r)>>1, nxt = node<<1;
        return merge(get(nxt, l, mid, x, y), get(nxt+1, mid+1, r, x, y));
    }
};

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

    void joinRange(int x, int y){

    }
};


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    ++n;
    DSU dsu(n);
    SEG seg(n);
    while(q--){
        int op, x, y; cin >> op >> x >> y;
        if(op == 1){
            seg.update(1, 0, n-1, x, 0);
            seg.update(1, 0, n-1, y, 0);
            dsu.join(x, y);
        }else if(op == 2){
            int pos = seg.gfa(1, 0, n-1, 1, x);
            while(pos != -1 && pos <= y){
                if(pos-1 >= x) dsu.join(pos-1, pos);
                if(pos+1 <= y) dsu.join(pos, pos+1); 
                seg.update(1, 0, n-1, pos, 0);
                pos = seg.gfa(1, 0, n-1, 1, x);
            }
        }else{
            cout << (dsu.find(x) == dsu.find(y) ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}
