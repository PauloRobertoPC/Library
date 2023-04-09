#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<vector<int>> M(n, vector<int>(n)), E(n, vector<int>(n, 1));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> M[i][j];

    bool ok = true;
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ok &= (M[i][k]+M[k][j] >= M[i][j]);
                if(i == k || j == k) continue;
                if(M[i][k]+M[k][j] == M[i][j]) E[i][j] = 0;
            }
        }
    }

    if(!ok){
        cout << "-1\n";
        return 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << M[i][j]*E[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
