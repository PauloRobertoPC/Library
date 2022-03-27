#define maxn 200010     //max number of vertices

int sz[maxn];           //subtree's size
bitset<maxn> used;      //used[u] = 1 if vertex 'u' is already a centroid **Important for make the Centroid Tree**
vector<int> adj[maxn];  //adjacency list of tree
vector<int> cadj[maxn]; //adjacency list of centroid tree

void szSubTree(int u, int p){
   sz[u] = 1;
   for(int v:adj[u])
      if(v != p && !used[v])
         szSubTree(v, u), sz[u] += sz[v];
}

//sTree is the the subtree's size of vertex 'u' after run szSubtree
int calcCentroid(int u, int p, int sTree){
   for(int v:adj[u])
      if(v != p && !used[v] && sz[v]*2 > sTree)
         return calcCentroid(v, u, sTree); 
   return u;
}

int centroid(int u){
   szSubTree(u, -1); 
   int cent = calcCentroid(u, -1, sz[u]);
   used[cent] = 1;
   return cent;
}

int centroidTree(int u){
   u = centroid(u);
   for(int v:adj[u]){
      if(!used[v]){
         int a = centroidTree(v);
         cadj[u].emplace_back(a); 
         cadj[a].emplace_back(u); 
      }
   }
   return u;
}
