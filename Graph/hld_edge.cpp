//build_hld O(n)
//get and update O((log n)^2)
//get_subtree, update_subtree and LCA O(log n)

struct segtree{ ... };

struct hld{
   int t;
	vector<int> pos, sz;
	vector<int> wei, dad;
	vector<int> h, val;
	vector<vector<pair<int, int>>> adj;
   segtree s;

   hld(){}
   hld(int n){
      pos.assign(n+1, 0); 
      sz.assign(n+1, 0); 
      wei.assign(n+1, 0); 
      dad.assign(n+1, 0); 
      val.assign(n+1, 0); 
      h.assign(n+1, 0); 
      adj.assign(n+1, vector<pair<int, int>>()); 
   }

	void build_hld(int u, int p, int f){
		val[t] = wei[u]; pos[u] = t++; sz[u] = 1;
		for (auto &par:adj[u]){
         if(par.first != p){
            int v = par.first, w = par.second;
		   	wei[v] = w; dad[v] = u;
		   	h[v] = (par == adj[u][0] ? h[u] : v);
		   	build_hld(v, u, f); 
            sz[u] += sz[v];
		   	if (sz[v] > sz[adj[u][0].first] || adj[u][0].first == p) swap(par, adj[u][0]);
		   }
      }
		if (p*f == -1) h[u] = u, t = 0, build_hld(u, -1, 0);
	}

	void build(int root){
		t = 0;
		build_hld(root, -1, 1);
      s.assign(val, t);
      s.build(1, 0, t-1);
	}

   segtree::no get(int u, int v){
		if (u == v) return s.neut;
		if (pos[u] < pos[v]) swap(u, v);
		if (h[u] == h[v]) return s.get(1, 0, t-1, pos[v]+1, pos[u]);
		return segtree::merge(s.get(1, 0, t-1, pos[h[u]], pos[u]) , get(dad[h[u]], v));
	}

	void update(int u, int v, int x){
		if (u == v) return;
		if (pos[u] < pos[v]) swap(u, v);
		if (h[u] == h[v]) return (void)s.update(1, 0, t-1, pos[v]+1, pos[u], x);
		s.update(1, 0, t-1, pos[h[u]], pos[u], x); update(dad[h[u]], v, x);
	}

   segtree::no get_subtree(int u){
		if (sz[u] == 1) return s.neut;
		return s.get(1, 0, t-1, pos[u]+1, pos[u]+sz[u]-1);
	}

	void update_subtree(int u, int x){
		if (sz[u] == 1) return;
		s.update(1, 0, t-1, pos[u]+1, pos[u]+sz[u]-1, x);
	}

	int LCA(int u, int v){
		if (pos[u] < pos[v]) swap(u, v);
		return h[u] == h[v] ? v : LCA(dad[h[u]], v);
	}
};
