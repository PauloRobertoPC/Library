#include <bits/stdc++.h>

using namespace std;

#define maxn  2510

int n, m;
char M[maxn][maxn];
int rl[maxn][maxn], rr[maxn][maxn], cd[maxn][maxn], cu[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i = 0; i < maxn; i++)
        for(int j = 0; j < maxn; j++)
            rr[i][j] = cd[i][j] = maxn+10;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> M[i][j];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(M[i][j] == '#') rl[i][j] = j;
            else rl[i][j] = rl[i][j-1];
        }
        for(int j = m; j >= 1; j--){
            if(M[i][j] == '#') rr[i][j] = j;
            else rr[i][j] = rr[i][j+1];
        }
    }
    for(int j = 1; j <= m; j++){
        for(int i = 1; i <= n; i++){
            if(M[i][j] == '#') cu[i][j] = i;
            else cu[i][j] = cu[i-1][j];
        }
        for(int i = n; i >= 1; i--){
            if(M[i][j] == '#') cd[i][j] = i;
            else cd[i][j] = cd[i+1][j];
        }
    }
    int q;
    cin >> q;
    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        bool ok = false;
        int xm = min(x1, x2), ym = min(y1, y2);
        int xM = max(x1, x2), yM = max(y1, y2);
        if(x1 == x2){
            ok |= (rr[x1][ym] > yM);            
        }else if(y1 == y2){
            ok |= (cd[xm][y1] > xM);            
        }else{
            if(y1 > y2){
                swap(x1, x2);
                swap(y1, y2);
            }
            if(x1 < x2){
                // [x1][y2] left, down
                ok |= (rl[x1][y2] < y1 && cd[x1][y2] > x2);
                // [x2][y1] right, up
                ok |= (rr[x2][y1] > y2 && cu[x2][y1] < x1);
            }else{
                // [x2][y1] right, down
                ok |= (rr[x2][y1] > y2 && cd[x2][y1] > x1);
                // [x1][y2] left, up
                ok |= (rl[x1][y2] < y1 && cu[x1][y2] < x2);
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
