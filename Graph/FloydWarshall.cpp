// max number of vertices
#define maxn 451
#define INF int(1e8)

int n;              // number of vertices
int M[maxn][maxn];  // Adjacency Matrix

void fw(){
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                M[i][j] = min(M[i][j], M[i][k]+M[k][j]);
}

// M[u][v] = INF then no path u -> v
// M[u][v] = -INF then the path u -> ... -> v has a negative cycle
// otherwise M[u][v] = dist(u, v)
void fw_negative_cycle(){
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(M[i][k] < INF && M[k][j] < INF)
                    M[i][j] = min(M[i][j], M[i][k]+M[k][j]);
     for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) 
            for(int k = 0; k < n; k++) 
                if(M[k][k] < 0 && M[i][k] != INF && M[k][j] != INF) 
                    M[i][j] = -INF;
}
