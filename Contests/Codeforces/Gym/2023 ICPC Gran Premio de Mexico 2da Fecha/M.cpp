#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define mod 998244353
#define maxn ll(5e4+10)

typedef long long ll;

ll n;
ll dp[maxn];
ll p[maxn];

ll solve(ll i){
    if(i >= n) return 0;
    if(dp[i] != -1) return dp[i];

    dp[i] = (p[i] == *min_element(p+i, p+n));

    ll mmin = p[i];
    for(ll j = i+1; j < n; j++){
        mmin = min(mmin, p[j]);
        if(min(p[i], p[j]) == mmin)
            dp[i] = (dp[i]+solve(j))%mod;
    }

    return dp[i];
}

int main(){
    cin >> n;
    for(ll i = 0; i < n; i++) cin >> p[i];

    memset(dp, -1, sizeof(dp));

    ll ans = 0, mmin = p[0];
    for(ll i = 0; i < n; i++){
        mmin = min(mmin, p[i]);
        if(p[i] == mmin)
            ans = (ans+solve(i))%mod;
    }
    cout << ans << "\n";

    return 0;
}
