#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> M(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> M[i][j];
    int mmax = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0, curr = 1; j < m-1; j++){
            if(abs(M[i][j]-M[i][j+1]) <= 1){
                ++curr;
                mmax = max(mmax, curr);
            }else{
                curr = 1;
            }
        }
    }
    for(int j = 0; j < m; j++){
        for(int i = 0, curr = 1; i < n-1; i++){
            if(abs(M[i][j]-M[i+1][j]) <= 1){
                ++curr;
                mmax = max(mmax, curr);
            }else{
                curr = 1;
            }
        }
    }
    cout << mmax << "\n";
    return 0;
}
