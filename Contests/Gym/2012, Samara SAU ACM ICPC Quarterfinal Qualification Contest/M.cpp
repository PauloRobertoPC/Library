#include <bits/stdc++.h>

using namespace std;

#define INF int(1e9)

int main(){
    int n;
    cin >> n;
    vector<int> v(n), next(200010, -1);
    vector<array<int, 2>> jump(n);
    for(int &x:v) cin >> x;
    for(int i = n-1; i >= 0; i--){
        jump[i][0] = jump[i][1] = i+1; 
        if(next[v[i]] != -1)
            jump[i][1] = next[v[i]]; 
        next[v[i]] = i;
    }
    vector<int> dp(n, INF); dp[0] = 0;
    for(int i = 0; i < n; i++){
        if(jump[i][0] < n)
            dp[jump[i][0]] = min(dp[jump[i][0]], dp[i]+1);
        if(jump[i][1] < n)
            dp[jump[i][1]] = min(dp[jump[i][1]], dp[i]+1);
    }
    cout << dp[n-1] << "\n";
    return 0;
}
