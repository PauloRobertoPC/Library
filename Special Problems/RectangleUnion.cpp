
#include <bits/stdc++.h>

using namespace std;

struct event{
   int x, y0, y1;
   bool tipo;
   event(){x=y0=y1=0;}
   event(int a, int b, int c, bool d){x=a; y0=b; y1=c; tipo=d;}
};

bool comp(event a, event b){
   return a.x < b.x;
}

struct segtree{
   struct no{
      int val, qtd, lazy;
      no(){ val = int(1e9+10); qtd = lazy= 0;}      //Usualy Neutral Element
      no(int v){ val = v; qtd = 1; lazy = 0;}
   };
   no neut;
   vector<no> seg;

   segtree(){}
   segtree(int n){seg.resize(n<<2);}

   static no merge(no a, no b){
      no c;
      if(a.val==b.val){
         c.val = a.val;
         c.qtd = a.qtd+b.qtd;
      }else if(a.val < b.val){
         return a;
      }else{
         return b;
      }
      return c;
   }

   void build(int node, int l, int r){
      if(l == r){
         seg[node] = no(0);
         return;
      }
      int mid = (l+r)>>1, nxt = node<<1;
      build(nxt, l, mid);
      build(nxt+1, mid+1, r);
      seg[node] = merge(seg[nxt], seg[nxt+1]);
   }

   void push(int node, int l, int r){
      if(seg[node].lazy){
         seg[node].val += seg[node].lazy;
         if(l != r){
            int nxt = node<<1;
            seg[nxt].lazy += seg[node].lazy;
            seg[nxt+1].lazy += seg[node].lazy;
         }
         seg[node].lazy = 0;
      }
   }

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

int main(){
   int n; cin >> n; 
   vector<event> r;
   for(int i = 0, x0, x1, y0, y1; i < n; i++){
      cin >> x0 >> y0 >> x1 >> y1;
      r.push_back(event(x0, y0, y1, 0));
      r.push_back(event(x1, y0, y1, 1));
   }
   sort(r.begin(), r.end(), comp);
   int yAxis = int(1e5+10);
   segtree s(yAxis);
   s.build(1, 0, yAxis-1);
   n <<= 1;
   int ans = 0;
   for(int i = 1; i < n; i++){
      if(!r[i-1].tipo) s.update(1, 0, yAxis-1, r[i-1].y0+1, r[i-1].y1, 1);    
      else s.update(1, 0, yAxis-1, r[i-1].y0+1, r[i-1].y1, -1); 
      segtree::no res = s.get(1, 0, yAxis-1, 0, yAxis-1);
      ans += (r[i].x-r[i-1].x)*(yAxis-(res.qtd*(res.val==0)));
   }
   cout << ans << "\n";
   return 0;
}
