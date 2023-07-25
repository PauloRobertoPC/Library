#include <bits/stdc++.h>

using namespace std;

#define LOG 21

struct segtree{
    struct no{
        int val, lazy;
        no(){ val = 0; lazy = -1;}
        no(int v){ val = v; lazy = -1;}
    };
    no neut;
    vector<no> seg, v;

    segtree(){}
    void assign(int n){seg.resize(n<<2);}

    static no merge(no a, no b){
        no c;
        c.val = a.val+b.val;
        return c;
    }
    void push(int node, int l, int r){
        if(seg[node].lazy != -1){
            seg[node].val = (r-l+1)*seg[node].lazy;
            if(l != r){
                int nxt = node<<1;
                seg[nxt].lazy = seg[node].lazy;
                seg[nxt+1].lazy = seg[node].lazy;
            }
            seg[node].lazy = -1;
        }
    }

    void update(int node, int l, int r, int x, int y, int val){
        push(node, l, r);
        if(l > y || r < x) return;
        if(l >= x && r <= y){
            seg[node].lazy = val;
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

struct hld{
    segtree s;
    int t;
    vector<int> pos, sz;
    vector<int> wei, val;
    vector<int> h, dad, lvl;
    vector<vector<int>> adj, parent;

    hld(){}
    hld(int n){
        pos.assign(n+1, 0);
        sz.assign(n+1, 0);
        wei.assign(n+1, 0);
        val.assign(n+1, 0);
        h.assign(n+1, 0);
        lvl.assign(n+1, 0);
        dad.assign(n+1, 0);
        adj.assign(n+1, vector<int>());
        parent.assign(n+1, vector<int>(LOG, -1));
    }

    void build_hld(int u, int p, int f, int lv){
        lvl[u] = lv;
        val[pos[u] = t++] = wei[u]; sz[u] = 1;
        parent[u][0] = p;
        for(int i = 1; i < LOG; i++)
            if(parent[u][i-1] != -1)
                parent[u][i] = parent[parent[u][i-1]][i-1];
        for(auto &v:adj[u]){
            if(v != p){
                dad[v] = u;
                h[v] = (v == adj[u][0] ? h[u] : v);
                build_hld(v, u, f, lv+1);
                sz[u] += sz[v];
                if(sz[v] > sz[adj[u][0]] || adj[u][0] == p) swap(v, adj[u][0]);
            }
        }
        if(p*f == -1) h[u] = u, t = 0, build_hld(u, -1, 0, 0);
    }

    void build(int root){
        t = 0; 
        build_hld(root, -1, 1, 0);
        s.assign(t);
    }

    segtree::no get(int u, int v){
        if(pos[u] < pos[v]) swap(u, v);
        if(h[u] == h[v]) return s.get(1, 0, t-1, pos[v], pos[u]);
        return segtree::merge(s.get(1, 0, t-1, pos[h[u]], pos[u]), get(dad[h[u]], v));
    }

    void update(int u, int v, int x){
        if(pos[u] < pos[v]) swap(u, v);
        if(h[u] == h[v]) return (void)s.update(1, 0, t-1, pos[v], pos[u], x);
        s.update(1, 0, t-1, pos[h[u]], pos[u], x);
        update(dad[h[u]], v, x);
    }

    segtree::no get_subtree(int u){
        return s.get(1, 0, t-1, pos[u], pos[u]+sz[u]-1);
    }

    void update_subtree(int u, int x){
        s.update(1, 0, t-1, pos[u], pos[u]+sz[u]-1, x);
    }

    int LCA(int u, int v){
        if(pos[u] < pos[v]) swap(u, v);
        return (h[u] == h[v] ? v : LCA(dad[h[u]], v));
    }

    void apagar(int u){
        update_subtree(u, 0);
        update(1, u, 0);
    }

    void acender(int u){
        apagar(u);
        int v = u;
        update_subtree(u, 1);
        for(int i = LOG-1; i >= 0; i--){
            int aux = parent[v][i];
            if(aux==-1) continue;
            if(get_subtree(aux).val == sz[aux]-(lvl[u]-lvl[aux])){
                v = aux;
            }
        }
        update_subtree(v, 1);
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    hld hl(n);
    for(int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        hl.adj[u].emplace_back(v);
        hl.adj[v].emplace_back(u);
    }
    hl.build(1);
    int q; cin >> q;
    while(q--){
        int op, u; cin >> op >> u;
        if(op == 1){
            hl.acender(u);
        }else if(op == 2){
            hl.apagar(u);
        }else{
            cout << hl.get_subtree(u).val << "\n";
        }
    }
    return 0;
}
