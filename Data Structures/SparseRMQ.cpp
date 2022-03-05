//** data strucure works with 0-indexed vector and interval **
//preprocess = build O(n.log n)
//get O(1)

struct sparse{
   vector<vector<int>> st; //st[i][j] = max/min(v[i],...,v[i+(2^j)-1])
   int lg(int n){
      return 31-__builtin_clz(n);
   }
   void build(int *v, int n){
      int LG = lg(n);
      st.assign(n, vector<int>(LG+1));
      for(int i = 0; i < n; i++) st[i][0] = v[i];
      for(int j = 1; j <= LG; j++)
         for(int i = 0; i+(1<<j)-1 < n; i++)
            st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
   }
   int get(int l, int r){
      int LG = lg(r-l+1); 
      return min(st[l][LG], st[r-(1<<LG)+1][LG]);
   }
};
