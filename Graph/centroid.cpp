#define maxn int(1e5+10) // Max number of vertices

int sz[maxn], used[maxn];
int dad[maxn]; //dad[u] = dad of vertex 'u' in Centroid Tree
vector<int> adj[maxn];

void calcSize(int u, int p){
    sz[u] = 1;
    for(int v:adj[u])
        if(v != p && !used[v]) 
            calcSize(v, u), sz[u] += sz[v]; 
}

pair<int, int> calcCentroid(int u, int p, int tot){
    for(int v:adj[u])
    if(v != p && !used[v] && sz[v]*2 > tot)
        return calcCentroid(v, u, tot);
    for(int v:adj[u]) if(v != p && !used[v] && sz[v]*2 >= tot) return {u, v};
    return {u, u};
}

//The two centroids is returned because we use this code in isomorphism of trees
pair<int, int> centroid(int u){ //By default the first centroid is used
    calcSize(u, -1);
    pair<int, int> c = calcCentroid(u, -1, sz[u]);
    used[c.first] = 1; //Useful when we want to build Centroid Tree  
    return c;
}

int centroidTree(int u){
    u = centroid(u).first;
    for(int v:adj[u])
    if(!used[v]) 
        dad[centroidTree(v)] = u;
    return u;
}
