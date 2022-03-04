//'update' create a new tree based on old tree
//'get' return a range querie in a certain vesion of tree
//'get', 'update' and 'lb' run in O(log n)
//the tree consumes O(n log n) in memory

struct segtree{
   struct no{
      int val;
      no(){val=0;} //Usually neutral element
      no(int v){val=v;}
   };
   no neut;
   vector<no> seg;
   vector<int> roots, e, d; //root of each version of segtree, left and right child

   segtree(){
      create();      //0-th element is the null element, its a convetion made to root be the node 1
      create();      //Creating root node who is 1 because of null node
      roots.emplace_back(1); //root of first tree
      neut.val = 0;  //Set neutral element correctly
   } 

   no merge(no a, no b){
      no c(a.val+b.val);
      return c;
   }

   int create(){
      seg.emplace_back(neut); //Neutral element
      e.emplace_back(0);
      d.emplace_back(0);
      return seg.size()-1;
   }

   void update(int version, int l, int r, int pos, int val){
      roots.emplace_back(upd(roots[version], l, r, pos, val)); 
   }
   //val may not be a integer
   int upd(int node, int l, int r, int pos, int val){
      //Reusing old nodes
      int nnew = create(); //new node 
      seg[nnew] = seg[node];
      e[nnew] = e[node];
      d[nnew] = d[node];
      //Updating new version of tree with the new nodes;
      if(l==pos && r==pos){
         seg[nnew].val = seg[node].val+val;
         return nnew;
      }
      int mid=(l+r)>>1, aux; //using 'aux' to avoid bug/error in c++11 or earlier
      if(pos <= mid) aux = upd(e[nnew], l, mid, pos, val), e[nnew] = aux;
      else aux = upd(d[nnew], mid+1, r, pos, val), d[nnew] = aux;
      //merging correct values to the new tree
      seg[nnew] = merge(seg[e[nnew]], seg[d[nnew]]); 
      return nnew;
   }
   
   no get(int version, int l, int r, int x, int y){
      return gt(roots[version], l, r, x, y);
   }
   no gt(int node, int l, int r, int x, int y){
      if(node == 0) return neut;
      if(l > y || r < x) return neut;
      if(l >= x && r <= y) return seg[node];
      int mid=(l+r)>>1;
      return merge(gt(e[node], l, mid, x, y), gt(d[node], mid+1, r, x, y));
   }

   // Lower Bound, lb in short
   //Use Segtree of Sums with no negative numbers, using segtree as a frequency table
   //You can find the first position such that v[1+2+...+pos] <= k in [x,y] interval
   //** Otherwise return a position out of the ranger covered by seg **
   //You also can use to find 'k-th 1'
   int lb(int l, int r, int x, int y, int k){
      return LB(l, r, roots[x-1], roots[y], k);
   }
   int LB(int l, int r, int x, int y, int k){
      int tot = seg[y].val - seg[x].val; 
      if(tot < k) return int(1e9+10);
      if(l==r) return l;
      int mid=(l+r)>>1;
      int ans = LB(l, mid, e[x], e[y], k);
      if(ans == int(1e9+10)){
         int totLeft = seg[e[y]].val - seg[e[x]].val;
         ans = LB(mid+1, r, d[x], d[y], k-totLeft);
      }
      return ans;
   }

   // Lower Bound, lb in short
   //Use Segtree of Sums with no negative numbers, using segtree as a frequency table
   //You can find the first position in path a -> b such that v[a,...,b] <= k
   //** Otherwise return a position out of the ranger covered by seg **
   //You also can use to find 'k-th 1'
   int lbTree(int l, int r, int a, int b, int lca, int dadLCA, int k){
      return LBTREE(l, r, roots[a], roots[b], roots[lca], roots[dadLCA], k);
   }
   int LBTREE(int l, int r, int a, int b, int lca, int dadLCA, int k){
      int tot = seg[a].val + seg[b].val - seg[lca].val - seg[dadLCA].val; 
      if(tot < k) return int(1e9+10);
      if(l==r) return l;
      int mid=(l+r)>>1;
      int ans = LBTREE(l, mid, e[a], e[b], e[lca], e[dadLCA], k);
      if(ans == int(1e9+10)){
         int totLeft = seg[e[a]].val + seg[e[b]].val - seg[e[lca]].val - seg[e[dadLCA]].val;
         ans = LBTREE(mid+1, r, d[a], d[b], d[lca], d[dadLCA], k-totLeft);
      }
      return ans;
   }
};
