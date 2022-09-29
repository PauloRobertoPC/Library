#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c, d, na, nb;
    cin >> a >> b >> c >> d;
    map<int, map<int, int>> dist;
    queue<pair<int, int>> q; q.push({a, b});
    dist[0][0] = 20;
    dist[0][1] = 20;
    dist[1][0] = 20;
    dist[1][1] = 20;
    dist[a][b] = 0;
    while(!q.empty()){
        tie(a, b) = q.front(); q.pop(); 
        if(a ==  c && b == d){
            cout << dist[a][b] << "\n";
            return 0;
        }
        na = a^1, nb = b;
        if(dist[a][b] + 1 < dist[na][nb]){
            dist[na][nb] = dist[a][b] + 1;
            q.push({na, nb});
        }
        na = a^1, nb = b^1;
        if(dist[a][b] + 1 < dist[na][nb]){
            dist[na][nb] = dist[a][b] + 1;
            q.push({na, nb});
        }
    }
    return 0;
}
