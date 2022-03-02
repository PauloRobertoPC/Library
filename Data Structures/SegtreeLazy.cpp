//Build O(n)
//Others O(log n)

struct segtree{
   struct no{
      int val, lazy;
      no(){ val = lazy= 0;}      //Usualy Neutral Element
      no(int v){ val = v; lazy = 0;}
   };
   no neut;
   vector<no> seg, v;

   segtree(){}
   segtree(int n, vector<no> &vv){v = vv; seg.resize(n<<2);}
   void assign(int n, vector<no> &vv){v = vv; seg.resize(n<<2);}

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

   // Lower Bound, lb in short
   //Use Segtree of Sums with no negative numbers
   //You can find the first position such that v[1+2+...+pos] <= k
   //Otherwise return -1
   //You also can use to find 'k-th 1'
   int lb(int node, int l, int r, int k){
      push(node, l, r);
      if(seg[node].val < k) return -1;
      if(l == r) return l;
      int mid = (l+r)>>1, nxt = node<<1;
      if(seg[nxt].val >= k) return lb(nxt, l, mid, k);	
      return lb(nxt+1, mid+1, r, k-seg[nxt].val);
   }

   //Get first above, gfa in short or binary search in segtree
   //Use Segtree of Max
   //You can find the first position such that v[pos] >= val and pos >= left
   //Otherwise return -1
   //You may modify like get the last above just change *1* with *2*
   int gfa(int node, int l, int r, int val, int left){
      push(node, l, r);
      if(seg[node].val < val) return -1;
      if(r < left) return -1;
      if(l == r) return l;	
      int mid = (l+r)>>1,nxt = node<<1;
      int ans = gfa(nxt, l, mid, val, left); //*1*		
      if(ans == -1)
         ans =  gfa(nxt+1, mid+1, r, val, left); //*2*
      return ans;
   }
};
