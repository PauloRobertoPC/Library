#include <bits/stdc++.h>

using namespace std;

#define maxn ll(3e3+10)

typedef long long ll;

ll h, w;
ll M[maxn][maxn];
ll P[maxn][maxn];

ll ok(ll i, ll j, ll n){
    ll ni = i+n-1;
    ll nj = j+n-1;
    if(ni > h) return 0;
    if(nj > w) return 0;
    ll sum = P[ni][nj] - P[ni][j-1] - P[i-1][nj] + P[i-1][j-1];
    return (sum == 0);
}

ll bb(ll i, ll j){
    ll l = 0, r = 3001, mid;
    while(l < r-1){
        mid = (l+r)/2;
        if(ok(i, j, mid)) l = mid;
        else r = mid;
    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> h >> w >> n;
    for(ll i = 0; i < n; i++){
        ll a, b; cin >> a >> b; M[a][b] = 1;
    }
    for(ll j = 1; j <= w; j++)
        for(ll i = 1; i <= h; i++)
            P[i][j] = M[i][j] + P[i-1][j] + P[i][j-1] - P[i-1][j-1];
    ll ans = 0;
    for(ll i = 1; i <= h; i++)
        for(ll j = 1; j <= w; j++)
            ans += bb(i, j);
    cout << ans << "\n";
    return 0;
}
