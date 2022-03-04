//create O(1)
//All the others methods run in O(log n)

struct segtree{
   struct no{
      int val;
      no(){val=0;} //Usually neutral element
      no(int v){val=v;}
   };
   no neut;
   vector<no> seg;
   vector<int> lazy, e, d; //lazy, left and right child

   segtree(){
      create();      //0-th element is the null element, its a convetion made to root be the node 1
      create();      //Creating root node who is 1 because of null node
      neut.val = 0;  //Set neutral element correctly
   } 

   no merge(no a, no b){
      no c(a.val+b.val);
      return c;
   }

   int create(){
      seg.emplace_back(neut); //Neutral element
      lazy.emplace_back(0);   //Neutral element in lazy
      e.emplace_back(0);
      d.emplace_back(0);
      return seg.size()-1;
   }
   
   void push(int node, int l, int r){
      if(node != 0 && lazy[node]){
         seg[node].val += (r-l+1)*lazy[node];
         if(l != r){
            int aux;
            if(e[node] == 0) aux = create(), e[node] = aux;
            if(d[node] == 0) aux = create(), d[node] = aux;
            lazy[e[node]] += lazy[node];
            lazy[d[node]] += lazy[node];
         }
         lazy[node] = 0;
      }
   }
   //TODO: update may creating more nodes than necessary
   //val may not be a integer
   void update(int node, int l, int r, int x, int y, int val){
      push(node, l, r);
      if(l > y || r < x) return;
      if(l>=x && r<=y){
         lazy[node] += val;
         push(node, l, r);
         return;
      }
      int mid=(l+r)>>1, aux; //Watch out, when you use negative inteval (l+r)/2 != (l+r)>>1
      //we use 'aux' below to avoid bug/error in c++ 11 or previous versions
      if(e[node] == 0) aux = create(), e[node] = aux;
      update(e[node], l, mid, x, y, val);
      if(d[node] == 0) aux = create(), d[node] = aux;
      update(d[node], mid+1, r, x, y, val);
      push(e[node], l, mid); push(d[node], mid+1, r);
      seg[node] = merge(seg[e[node]], seg[d[node]]);
   }

   no get(int node, int l, int r, int x, int y){
      push(node, l, r);
      if(node == 0) return neut;
      if(l > y || r < x) return neut;
      if(l >= x && r <= y) return seg[node];
      int mid=(l+r)>>1;
      return merge(get(e[node], l, mid, x, y), get(d[node], mid+1, r, x, y));
   }

   // Lower Bound, lb in short
   //Use Segtree of Sums with no negative numbers
   //You can find the first position such that v[1+2+...+pos] <= k
   //** Otherwise return a position out of the ranger covered by seg **
   //You also can use to find 'k-th 1'
   int lb(int node, int l, int r, int k){
      push(node, l, r);
      if(node == 0) return int(1e9+10);
      if(seg[node].val < k) return int(1e9+10);
      if(l==r) return l;
      int mid=(l+r)>>1;
      int ans = lb(e[node], l, mid, k);
      if(ans == int(1e9+10)) ans = lb(d[node], mid+1, r, k-seg[e[node]].val);
      return ans;
   }

   //Get first above, gfa in short or binary search in segtree
   //Use Segtree of Max
   //You can find the first position such that v[pos] >= val and pos >= left
   //** Otherwise return a position out of the range covered by seg **
   //You may modify, like get the last above, its just change *1* with *2*
   int gfa(int node, int l, int r, int val, int left){
      push(node, l, r);
      if(node == 0) return int(1e9+10);
     	if(seg[node].val < val) return int(1e9+10);
     	if(r < left) return int(1e9+10);
     	if(l == r) return l;	
     	int mid = (l+r)>>1;
     	int ans = gfa(e[node], l, mid, val, left); //*1*		
     	if(ans == int(1e9+10))
         ans =  gfa(d[node], mid+1, r, val, left); //*2*
     	return ans;
   }
};
