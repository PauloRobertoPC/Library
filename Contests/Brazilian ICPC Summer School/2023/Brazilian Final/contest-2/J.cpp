#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m, k;
ll a[19];
ll bonus[19][19];
ll dp[19][1<<19];

ll solve(ll last, ll mask){
    if(__builtin_popcount(mask) == m+1) return 0;
    if(dp[last][mask] != -1) return dp[last][mask];
    dp[last][mask] = 0;
    for(ll i = 1; i <= n; i++)
        if((mask&(1<<i)) == 0)
            dp[last][mask] = max(dp[last][mask], a[i]+bonus[last][i]+solve(i,mask|(1<<i)));
    return dp[last][mask];
}

int main(){
    cin >> n >> m >> k;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    while(k--){
        ll u, v, w; cin >> u >> v >> w;
        bonus[u][v] = w;
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 1) << "\n";
    return 0;
}
// Description: DP - Bitmask DP
