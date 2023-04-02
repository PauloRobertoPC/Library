#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int &x:v) cin >> x;
    int mmax = *max_element(v.begin(), v.end());
    vector<int> mv = {1, 1};
    for(int i = 2; mv[i-2]+mv[i-1] <= mmax; i++) mv.emplace_back(mv[i-2]+mv[i-1]);
    vector<int> dp(mmax+1, 0);
    for(int i = 1; i <= mmax; i++){
        vector<int> used(mv.size()+2, 0); 
        for(int j = 1; j < mv.size(); j++){
            if(i - mv[j] < 0) continue;
            used[dp[i-mv[j]]] = 1;
        }
        int j = 0;
        for(; used[j]; j++);
        dp[i] = j;
    }
    int xr = 0;
    for(int x:v) xr ^= dp[x];
    cout << (xr ? "Ada" : "Vinit") << "\n";
    return 0;
}
// Description: Math - Game Theory -> Sprange Grundy
