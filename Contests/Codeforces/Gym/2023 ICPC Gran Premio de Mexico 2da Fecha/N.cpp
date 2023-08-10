#include <bits/stdc++.h>

using namespace std;

#define maxn ll(1e5+110)

typedef long long ll;

ll n, k;
ll v[maxn], t[maxn];
ll dp[maxn][110];

ll solve(ll l, ll r, ll p, ll m, ll c){
    if(dp[l][c] != -1) return dp[l][c];
    if(c > k) return m;

    ll left = 0, right = 0;
    if(l >= 1){
        if(t[l] == 1)
            left = solve(l-1, r, p+v[l], m, c+1);
        else if(t[l] == 2 && p >= v[l])
            left = solve(l-1, r, p-v[l], m+v[l], c+1);
    }

    if(r <= n){
        if(t[r] == 1)
            right = solve(l, r+1, p+v[r], m, c+1);
        else if(t[r] == 2 && p >= v[r])
            right = solve(l, r+1, p-v[r], m+v[r], c+1);
    }

    return dp[l][c] = max({left, right, m});
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    k = min(k, n);
    for(ll i = 1; i <= n; i++) cin >> v[i];
    for(ll i = 1; i <= n; i++) cin >> t[i];
    for(ll i = 1; i < k; i++) v[n+i] = v[i], t[n+i] = t[i];
    n += k-1;
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    for(ll i = 1; i < n; i++)
        ans = max(ans, solve(i, i+1, 0, 0, 1));
    cout << ans << "\n";
    return 0;
}
