#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

struct segtree{
   struct no{
      ll maximo, pref, suf, sum;
      no(){ maximo = pref = suf = sum = 0;} 
      no(ll v){ maximo = pref = suf = max(0LL, v); sum = v;}
      //Watch out with the max if you want choose at least a number
   };
   int n;
   no neut;
   vector<int> v;
   vector<no> seg;

   segtree(){}
   segtree(int nn, vector<int> &vv){n = nn; v = vv; seg.resize(n<<2);}
   void assign(int nn, vector<int> &vv){n = nn; v = vv; seg.resize(n<<2);}

   static no merge(no a, no b){
      no c;
      c.maximo = max({a.maximo, b.maximo, a.suf+b.pref});
      c.pref = max(a.pref, a.sum+b.pref);
      c.suf = max(b.suf, b.sum+a.suf);
      c.sum = a.sum+b.sum;
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
   
   //val may not be a integer
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

   no neutral(){
      return neut;
   }

   no get(int node, int l, int r, int x, int y){
      if(l > y || r < x) return neutral();
      if(l >= x && r <= y) return seg[node];
      int mid = (l+r)>>1, nxt = node<<1;
      return merge(get(nxt, l, mid, x, y), get(nxt+1, mid+1, r, x, y));
   }
};

int main(){
   ll pos, val;
   ll n, m; cin >> n >> m;
   vector<int> v(n);
   for(ll i = 0; i < n; i++) cin >> v[i];
   segtree s(n, v);
   s.build(1, 0, n-1);
   cout << s.get(1, 0, n-1, 0, n-1).maximo << "\n";	
   while(m--){
      cin >> pos >> val;
      s.update(1, 0, n-1, pos, val);
      cout << s.get(1, 0, n-1, 0, n-1).maximo << "\n";	
   }	
   return 0;
}
