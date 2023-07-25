#include <bits/stdc++.h>

using namespace std;

#define maxn 2025

typedef unsigned long long ll;

ll M[maxn][maxn], P[maxn][maxn];

void init(){
    for(ll i = 1, cnt = 1; i <= 2023; i++)
        for(ll j = 1; j <= i && cnt <= 1000001; j++, cnt++)
            M[i][j] = cnt*cnt;
    for(ll i = 1, cnt = 1; i <= 2023; i++)
        for(ll j = 1; j <= 2023; j++)
            P[i][j] = P[i][j-1]+M[i][j];
}

pair<ll, ll> find(ll n){
    ll i = 1, sum = 1;
    for(; sum <= n; i++) sum += i;
    --i; sum -= i;
    ll j = 1;
    while(sum < n) ++sum, ++j; 
    return {i, j};
}

int main(){
    init();
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n; 
        ll i, j, l, r; tie(i, j) = find(n);
        l = r = j;
        ll ans = 0;
        while(i >= 1){
            ans += (P[i][r]-P[i][l-1]); 
            // cout << i << " " << l << " " << r << "\n"; 
            --i;
            l = max(ll(1), l-1);
            // r = min(i, r+(r!=1));
        }
        // cout << n << ": ";
        cout << ans << "\n";
    }
    return 0;
}
