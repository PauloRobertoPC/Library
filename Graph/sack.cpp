//Offline solution for query in subtrees
//Complexity O(n . logn)

#define maxn int(1e5 + 10) // Maximum number of vertices

int n; //Number of vertices
int ans; //May be a vector
int sz[maxn], fst[maxn], lst[maxn], euler[maxn], timer;
vector<int> adj[maxn];

void calc(int u, int p) {
    sz[u] = 1;
    fst[u] = timer;
    euler[timer++] = u;
    for (int v : adj[u])
    if (v != p)
        calc(v, u), sz[u] += sz[v];
    lst[u] = timer;
}

void add(int v);

void del(int v);

int search(int u);

void dfs(int u, int p, int keep){
    int mx = -1, bigChild = -1;
    for(int v:adj[u]) if(v != p && sz[v] > mx) mx = sz[v], bigChild = v;	
    for(int v:adj[u]) if(v != p && v != bigChild) dfs(v, u, 0);	
    if(bigChild != -1) dfs(bigChild, u, 1);
    add(u);
    for(int v:adj[u]) if(v != p && v != bigChild) for(int j = fst[v]; j < lst[v]; j++) add(euler[j]);	
    //Here all the vertcies in u's subtree are already in our structure
    //Processing...
    ans += search(u); 
    //Finishing Processing
    if(!keep){
        for(int j = fst[u]; j < lst[u]; j++) del(euler[j]);	
    }
}

//Sack with vertex 'u' being LCA
void dfs(int u, int p, int keep) {
    int mx = -1, bigChild = -1;
    for (int v : adj[u])
    if (v != p && sz[v] > mx)
        mx = sz[v], bigChild = v;
    for (int v : adj[u])
    if (v != p && v != bigChild)
        dfs(v, u, 0);
    if (bigChild != -1)
        dfs(bigChild, u, 1);
    for (int v : adj[u]) {
        if (v != p && v != bigChild) {
            for (int j = fst[v]; j < lst[v]; j++) ans += search(euler[j]);  //Processing
            for (int j = fst[v]; j < lst[v]; j++) add(euler[j]);            //Adding
        }
    }
    ans += search(u);   //Processing
    add(u);             //Adding
    if (!keep) for (int j = fst[u]; j < lst[u]; j++) del(euler[j]);
}
