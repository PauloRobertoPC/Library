#include <bits/stdc++.h>

using namespace std;

#define INF int(1e5)

int s, m;
int M[30][30]; // Weigth Edge Dist
int E[30][30]; // Edge Dist
int dad[30][30]; // Dad

void fw(){
    for(int k = 0; k < s; k++){
        for(int i = 0; i < s; i++){
            for(int j = 0; j < s; j++){
                if(M[i][k]+M[k][j] < M[i][j]){
                    M[i][j] = M[i][k]+M[k][j];
                    E[i][j] = E[i][k]+E[k][j];
                    dad[i][j] = dad[k][j];
                }else if(M[i][k]+M[k][j] == M[i][j] && E[i][k]+E[k][j] < E[i][j]){
                    E[i][j] = E[i][k]+E[k][j];
                    dad[i][j] = dad[k][j];
                }
            }
        }
    }
}

void printPath(int i, int j, int d=0){
    bool ok = false;
    if(i != j) printPath(i, dad[i][j], d+1), ok = true;
    if(ok) cout << " ";
    cout << char(j+'A');
}

int main(){
    cin >> s >> m; 
    for(int i = 0; i <= s; i++)
        for(int j = 0; j <= s; j++)
            dad[i][j] = i,
            M[i][j] = 0 + (INF * (i != j)),
            E[i][j] = 0 + (INF * (i != j));
    while(m--){
        char u, v; int w;
        cin >> u >> v >> w;
        M[u-'A'][v-'A'] = w;
        E[u-'A'][v-'A'] = 1;
        M[v-'A'][u-'A'] = w;
        E[v-'A'][u-'A'] = 1;
    }
    fw();
    int q; cin >> q;
    while(q--){
        char u, v;
        cin >> u >> v;
        printPath(u-'A', v-'A');
        cout << "\n";
    }
    return 0;
}
