//create O(1)
//All the others methods run in O(log n)

struct segtree{
   struct no{
      int val;
      no(){val=-1;} //Usually neutral element
      no(int v){val=v;}
   };
   no neut;
   vector<no> seg;
   vector<int> e, d; //left and right child

   segtree(){
      create();      //0-th element is the null element, its a convetion made to root be the node 1
      create();      //Creating root node who is 1 because of null node
      neut.val = -1;  //Set neutral element correctly
   } 

   no merge(no a, no b){
      no c(max(a.val,b.val));
      return c;
   }

   int create(){
      seg.emplace_back(neut); //Neutral element
      e.emplace_back(0);
      d.emplace_back(0);
      return seg.size()-1;
   }
   
   //val may not be a integer
   void update(int node, int l, int r, int pos, int val){
      if(l > pos || r < pos) return;
      if(l==pos && r==pos){
         seg[node] = no(val);
         return;
      }
      int mid=(l+r)>>1, aux; //Watch out, when you use negative inteval (l+r)/2 != (l+r)>>1
      //we use 'aux' below to avoid bug/error in c++ 11 or previous versions
      if(pos <= mid){
         if(e[node] == 0) aux = create(), e[node] = aux;
         update(e[node], l, mid, pos, val);
      }else{
         if(d[node] == 0) aux = create(), d[node] = aux;
         update(d[node], mid+1, r, pos, val);
      }
      seg[node] = merge(seg[e[node]], seg[d[node]]);
   }

   no get(int node, int l, int r, int x, int y){
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
