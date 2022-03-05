//** Don't forget to fill dad array with -1 **
//Preprocess = dfs O(n.log n)
//up, LCA, kth, distEdge, distWeigth and RMQ O(log n)

//maxn is the max number of vertices
//LOG is the ceil of log2(maxn)
//lvl[u] = heigth of vertex u in tree
//dad[u][i] = (2^i)-th ancestor of vertex u
//val[u] = val of vertex u 
//dist[u] = dist in edge's weigth to the root
//M[u][i] = min/max between vertex u and its (2^i)-th ancestor

#define maxn int(1e5)+10
#define LOG 20

int lvl[maxn], dad[maxn][LOG]; 
int val[maxn], dist[maxn], M[maxn][LOG];
vector<pair<int, int>> adj[maxn];

void dfs(int u, int p, int h){
   lvl[u] = h;
   M[u][0] = val[u];  
   dad[u][0] = p;
   for(int i = 1; i < LOG; i++)
      if(dad[u][i-1] != -1)
         dad[u][i] = dad[dad[u][i-1]][i-1], M[u][i] = max(M[u][i-1], M[dad[u][i-1]][i-1]);
   for(auto par:adj[u])
      if(par.first != p)
         dist[par.first] = dist[u]+par.second, dfs(par.first, u, h+1);
}

//move up the vertex u to its k-th ancestor
int up(int u, int k){
   for(int i = LOG-1; i >= 0; i--)
      if(k&(1<<i) && dad[u][i] != -1)
         u = dad[u][i];
   return u;
}

int LCA(int u, int v){
   if(lvl[u] < lvl[v]) swap(u, v);
   u = up(u, lvl[u]-lvl[v]); 
   if(u == v) return u;
   for(int i = LOG-1; i >= 0; i--)
      if(dad[u][i] != dad[v][i])
         u = dad[u][i], v = dad[v][i];
   return dad[u][0];
}

int distEdge(int u, int v){
   return lvl[u]+lvl[v]-2*lvl[LCA(u, v)];
}

int distWeigth(int u, int v){
   return dist[u]+dist[v]-2*dist[LCA(u, v)];
}

//k-th vertex in the path u -> v where u is 0-th vertex in path
int kth(int u, int v, int k){
   int lca = LCA(u, v);
   if(lvl[u]-lvl[lca] >= k) return up(u, k);
   k -= lvl[u]-lvl[lca];
   return up(v, lvl[v]-lvl[lca]-k);
}

//max/min in the path u -> v
int RMQ(int u, int v){
   if(lvl[u] < lvl[v]) swap(u, v);
   int mmax = -1;
   for(int i = LOG-1; i >= 0; i--)
      if(dad[u][i] != -1 && lvl[dad[u][i]] >= lvl[v])
         mmax = max(mmax, M[u][i]), u = dad[u][i];
   if(u == v) return mmax;
   for(int i = LOG-1; i >= 0; i--){
      if(dad[u][i] != dad[v][i]){
         mmax = max({mmax, M[u][i], M[v][i]});
         u = dad[u][i], v = dad[v][i];
      }
   }
   mmax = max({mmax, M[u][0], M[v][0]});
   return mmax;
}
