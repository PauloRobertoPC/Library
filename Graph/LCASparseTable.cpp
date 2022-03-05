//** Watch out, the sparse table is 0-indexed **
//build O(n.log n)
//LCA O(1)

#define maxn int(1e5+10)

int lvl[maxn]; //lvl[u] = level of vertex u in tree
int euler[maxn]; //euler[i] = vertex found at i-th step in euler tour
int first[maxn]; //first[u] = the first position of vertex v in euler tour
int cnt; //auxiliar counter used in dfs, cnt = 0 every time you run bfs
vector<int> adj[maxn];

struct sparse{
   int *h, *fst; //heigth of each vertex and the first time in euler tour
   vector<vector<int>> st; 
   int lg(int n){
      return 31-__builtin_clz(n);
   }
   void build(int *euler2, int *lvl2, int *fst2, int n){ //n = tamanho de euler2
      h = lvl2, fst = fst2; 
      int LG = lg(n);
      st.assign(n, vector<int>(LG+1));
      for(int i = 0; i < n; i++) st[i][0] = euler2[i];
      for(int j = 1; j <= LG; j++)
         for(int i = 0; i+(1<<j)-1 < n; i++)
            st[i][j] = (h[st[i][j-1]] < h[st[i+(1<<(j-1))][j-1]] ? st[i][j-1] : st[i+(1<<(j-1))][j-1]);
   }
   int LCA(int u, int v){
      int l = min(fst[u], fst[v]), r = max(fst[u], fst[v]);
      int LG = lg(r-l+1);
      return (h[st[l][LG]] < h[st[r-(1<<LG)+1][LG]]) ? st[l][LG] : st[r-(1<<LG)+1][LG]; 
   }
};

void dfs(int u, int p, int h){
   first[u] = cnt;
   euler[cnt++] = u;
   lvl[u] = h;
   for(int v:adj[u])
      if(v != p)
         dfs(v, u, h+1), euler[cnt++] = u;
}
