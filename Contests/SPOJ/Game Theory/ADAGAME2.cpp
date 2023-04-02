#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m; 
        vector<int> r(m), v(n);
        for(int &x:r) cin >> x;
        for(int &x:v) cin >> x;
        int mmax = *max_element(v.begin(), v.end());
        vector<int> dp(mmax+1, 0);
        for(int i = 1; i <= mmax; i++){
            vector<int> used(m+2, 0);
            set<int> mex;
            for(int x:r){
                if(i-x < 0) continue;
                used[dp[i-x]] = 1;
            }
            int j = 0;
            for(; used[j]; ++j);
            dp[i] = j;
        }
        int xr = 0;
        for(int x:v) xr ^= dp[x];
        cout << (xr != 0 ? "Ada" : "Vinit") << "\n";
    }
    return 0;
}
// Description: Math - Game Theory -> Sprange Grundy
