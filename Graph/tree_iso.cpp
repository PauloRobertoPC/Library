//Isomorphism of trees
//equal and getID runs in O(n.logn)
//** Commom mistake: forget to clean the adjacency list when call getID or equal**

#define maxn int(1e5+10) // Max number of vertices
 
struct treeID{
    int id;
    map<map<int, int>, int> mpID;
    vector<int> sz, *adj;

    treeID(){ id = 0; sz.resize(maxn); }
    
    void calcSize(int u, int p){
        sz[u] = 1;
        for(int v:adj[u]) if(v != p) calcSize(v, u), sz[u] += sz[v]; 
    }
    pair<int, int> calcCentroid(int u, int p, int tot){
        for(int v:adj[u]) if(v != p && sz[v]*2 > tot) return calcCentroid(v, u, tot);
        for(int v:adj[u]) if(v != p && sz[v]*2 >= tot) return {u, v};
        return {u, u};
    }
    pair<int, int> centroid(int u){
        calcSize(u, -1);
        pair<int, int> c = calcCentroid(u, -1, sz[u]);
        return c;
    }

    int dfs(int u, int p){
        map<int, int> mp;
        for(int v:adj[u]) 
            if(v != p)
                ++mp[dfs(v, u)];
        if(!mpID.count(mp)) mpID[mp] = ++id;
        return mpID[mp];
    }
    
    //Return a unique id for each tree
    pair<int, int> getID(vector<int> *tree){
        adj = tree; 
        pair<int, int> cent = centroid(1);
        pair<int, int> ans = {dfs(cent.first, -1), dfs(cent.second, -1)}; 
        if(ans.first > ans.second) swap(ans.first, ans.second);
        return ans;
    }
    
    //Check if two trees are isomorphics
    bool equal(vector<int> *tree1, vector<int> *tree2){
        getID(tree1);
        return (getID(tree1) == getID(tree2)); 
    }
};
