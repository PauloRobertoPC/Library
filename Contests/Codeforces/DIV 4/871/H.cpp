#include <bits/stdc++.h>

using namespace std;

#define maxn ll(2e5+10)
#define mod ll(1e9+7)

typedef long long ll;

ll n, k;
ll v[maxn];
vector<vector<ll>> dp; //mask, pos

ll solve(ll mask, ll pos){
    if(pos == n || __builtin_popcount(mask) < k) return 0;
    if(dp[mask][pos] != -1)
        return dp[mask][pos];
    dp[mask][pos] = 0;
    ll mask2 = mask&v[pos];
    return dp[mask][pos] = (solve(mask, pos+1) + solve(mask2, pos+1) + (__builtin_popcount(mask2) == k))%mod;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t; cin >> t;
    while(t--){
        cin >> n >> k;
        dp.assign(128, vector<ll>(n, -1));
        for(ll i = 0; i < n; i++) cin >> v[i];
        cout << solve((1<<7)-1, 0) << "\n"; 
    }
    return 0;
}
