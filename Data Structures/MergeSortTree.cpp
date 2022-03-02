//build O(n.log n)
//update O(n)
//get O(log^2 n)

struct segtree{
   struct no{
      vector<int> v;
      no(){ v.clear();}      //Usualy Neutral Element
      no(int vv){ v.clear(); v.emplace_back(vv);}
   };
   vector<int> v;
   vector<no> seg;

   segtree(){}
   segtree(int n, vector<int> &vv){v = vv; seg.resize(n<<2);}

   no merge(no a, no b){
      no c;
      std::merge(a.v.begin(), a.v.end(), b.v.begin(), b.v.end(), back_inserter(c.v));
      return c;
   }

   void build(int node, int l, int r){
      if(l == r){
         seg[node] = no(v[l]);
         return;
      }
      int mid = (l+r)>>1, nxt = node<<1;
      build(nxt, l, mid);
      build(nxt+1, mid+1, r);
      seg[node] = merge(seg[nxt], seg[nxt+1]);
   }
   
   void update(int node, int l, int r, int pos, int val){
      if(l > pos || r < pos) return;
      if(l == pos && r == pos){
         seg[node] = no(val);
         return;
      }
      int mid = (l+r)>>1, nxt = node<<1;
      update(nxt, l, mid, pos, val);
      update(nxt+1, mid+1, r, pos, val);
      seg[node] = merge(seg[nxt], seg[nxt+1]);
   }

   //return how much elements is bigger than val
   int get(int node, int l, int r, int x, int y, int val){
      if(l > y || r < x) return 0;
      if(l >= x && r <= y)
         return seg[node].v.end()-upper_bound(seg[node].v.begin(), seg[node].v.end(), val);
      int mid = (l+r)>>1, nxt = node<<1;
      return get(nxt, l, mid, x, y, val)+get(nxt+1, mid+1, r, x, y, val);
   }
};
