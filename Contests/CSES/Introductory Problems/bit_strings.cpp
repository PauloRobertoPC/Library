#include <bits/stdc++.h>

using namespace std;

#define mod int(1e9+7)

typedef long long ll;

int main(){

    ll n; cin >> n;
    ll ans = 1;
    for(int i = 1; i <= n; i++) ans = (ans*2)%mod;
    cout << ans << "\n";
    return 0;
}
