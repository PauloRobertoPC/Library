#include <bits/stdc++.h>

using namespace std;

int M[101][101];

bool ok(int i, int j){
    return !(i == j || i == 0 || j == 0);
}

int calc_mex(int x, int y){
    vector<int> used(210, 0);
    for(int i = x-1; i >= 1; i--) if(ok(i, y)) used[M[i][y]] = 1; 
    for(int j = y-1; j >= 1; j--) if(ok(x, j)) used[M[x][j]] = 1; 
    for(int i = x-1, j = y-1; ok(i, j); i--, j--) if(ok(i, j)) used[M[i][j]] = 1; 
    for(int i = 0; i < used.size(); i++) if(!used[i]) return i;
    return 0;
}

int main(){
    memset(M, -1, sizeof(M)); 
    for(int i = 1; i <= 100; i++)
        for(int j = 1; j <= 100; j++)
            if(ok(i, j))   
                M[i][j] = calc_mex(i, j); 
    bool ans = false; 
    int n, xr = 0; cin >> n;
    while(n--){
        int i, j; cin >> i >> j;
        if(!ok(i, j))
            ans = true;
        else
            xr ^= M[i][j];
    }
    ans |= (xr != 0);
    cout << (ans ? "Y" : "N") << "\n";
    return 0;
}
// Description: Math - Game Theory Sprague-Grundy
