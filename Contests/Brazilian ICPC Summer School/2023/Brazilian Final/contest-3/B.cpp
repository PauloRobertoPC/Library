#include <bits/stdc++.h>

using namespace std;

#define maxn ll(1e5+10)

typedef long long ll;

ll v[maxn];

int main(){
    ll n, k; cin >> n >> k;
    while(n--){
        ll a, b; cin >> a >> b;
        v[a] += b;
    }
    for(ll i = 1; i < maxn; i++) v[i] += v[i-1];
    cout << lower_bound(v, v+maxn, k)-v << "\n";
    return 0;
}
// Descrition: Prefix Sum and Binary Search
