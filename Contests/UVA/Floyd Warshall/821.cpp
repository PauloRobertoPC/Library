#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

#define INF int(1e5)

int M[101][101];

void fw(){
    for(int k = 1; k <= 100; k++)
        for(int i = 1; i <= 100; i++)
            for(int j = 1; j <= 100; j++)
                M[i][j] = min(M[i][j], M[i][k]+M[k][j]);
}

int main(){
    int u, v, c = 1;
    while(cin >> u >> v){
        if(u == 0 && v == 0) break;
        for(int i = 1; i <= 100; i++)
            for(int j = 1; j <= 100; j++)
                M[i][j] = 0 + (INF * (i != j));
        M[u][v] = 1;
        while(cin >> u >> v){
            if(u == 0 && v == 0) break;
            M[u][v] = 1;
        }
        fw();
        int sum = 0, cnt = 0; 
        for(int i = 1; i <= 100; i++){
            for(int j = 1; j <= 100; j++){
                if(i == j || M[i][j] >= INF) continue;
                sum += M[i][j];
                ++cnt;
            }
        }
        cout << "Case " << c++ << ": average length between pages = "; 
        cout << fixed << setprecision(3) << (sum*1.0)/(cnt*1.0) << " clicks\n";
    }
    return 0;
}
