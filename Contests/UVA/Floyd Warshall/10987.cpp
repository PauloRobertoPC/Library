#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    for(int c = 1; c <= t; c++){
        int n; cin >> n;
        vector<vector<int>> M(n, vector<int>(n, int(1e7)));
        vector<vector<int>> ME(n, vector<int>(n, 1));
        for(int i = 0; i < n; i++){
            for(int j = 0, w; j < i; j++){
                cin >> w;
                M[i][j] = M[j][i] = w;
            }
            M[i][i] = 0;
        }

        bool ok = true;
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    ok &= (M[i][k]+M[k][j] >= M[i][j]); // if is not true M[i][j] is not min_dist(i, j)
                    if(i == j || i == k || j == k) continue; // i, j are endpoints then it does not help us
                    if(M[i][k]+M[k][j] == M[i][j]) //then we pass at least by k in the path i -> j, hence the edge M[i][j] does not exist
                        ME[i][j] = 0;
                }
            }
        }

        cout << "Case #" << c << ":\n";
        if(!ok){
            cout << "Need better measurements.\n\n";
            continue;
        }
        int m = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++)
                if(i != j)
                    m += ME[i][j];
        cout << m << "\n";
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                if(ME[i][j])
                    cout << i+1 << " " << j+1 << " " << M[i][j] << "\n";
        cout << "\n";
    }
    return 0;
}
