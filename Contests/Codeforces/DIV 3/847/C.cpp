#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<int>> ps(n, vector<int>(n-1));
        vector<int> f(n+1, 0);
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < n-1; j++){
                cin >> ps[i][j];
                if(!j) ++f[ps[i][j]];
            }
        }
        int mmax = -1;
        for(int i = 1; i <= n; i++){
            if(f[i] == n-1){
                mmax = i;
                break;
            }
        }
        cout << mmax << " ";
        for(int i = 0; i < n; i++){
            if(ps[i][0] != mmax){
                for(int x:ps[i]) cout << x << " "; cout << "\n";
                break;
            }
        }
    }
    return 0;
}
