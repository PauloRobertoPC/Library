//build_hld O(n)
//get and update O((log n)^2)
//get_subtree, update_subtree and LCA O(log n)

//pos[u] = position of vertex 'u' in array 'val'
//sz[u] = size of subtree rooted in vertex 'u'
//wei[u] = weigth of vertex 'u'
//val[i] = weigth of vertex 'u' whose pos['u'] = i
//h[u] = the head of chain of vertex 'u'
//dad[u] = the dad of vertex 'u'
//adj is the adjacency list

struct segtree{ ... };

struct hld{
   segtree s;
   int t;
   vector<int> pos, sz;
   vector<int> wei, val; 
   vector<int> h, dad;
   vector<vector<int>> adj;

   hld(){}
   hld(int n){
      pos.assign(n+1, 0);
      sz.assign(n+1, 0);
      wei.assign(n+1, 0);
      val.assign(n+1, 0);
      h.assign(n+1, 0);
      dad.assign(n+1, 0);
      adj.assign(n+1, vector<int>());
   }

   void build_hld(int u, int p, int f){
      val[pos[u] = t++] = wei[u]; sz[u] = 1;
      for(auto &v:adj[u]){
         if(v != p){
            dad[v] = u;
            h[v] = (v == adj[u][0] ? h[u] : v);
            build_hld(v, u, f);
            sz[u] += sz[v];
            if(sz[v] > sz[adj[u][0]] || adj[u][0] == p) swap(v, adj[u][0]);
         }
      }
      if(p*f == -1) h[u] = u, t = 0, build_hld(u, -1, 0);
   }

   void build(int root){
      t = 0; 
      build_hld(root, -1, 1);
      s.assign(val, t);
      s.build(1, 0, t-1);
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
};
