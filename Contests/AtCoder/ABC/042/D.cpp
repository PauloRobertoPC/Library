#include <bits/stdc++.h>

using namespace std;

#define mod ll(1e9+7)
#define maxn ll(1e6+10)

typedef long long ll;


ll fat[maxn], invf[maxn];

ll binpow(ll b, ll e){
    ll ans = 1;
    while(e){
        if(e&1) ans = (ans*b)%mod;
        b = (b*b)%mod;
        e >>= 1;
    }
    return ans;
}

ll choose(ll n, ll m){
    return (((fat[n]*invf[m])%mod)*invf[n-m])%mod;
}

int main(){
    fat[0] = invf[0] = 1;
    for(int i = 1; i < maxn; i++){
        fat[i] = (i*fat[i-1])%mod;
        invf[i] = binpow(fat[i], mod-2);
    }
    ll h, w, a, b;
    cin >> h >> w >> a >> b;
    a = h-a; ++b;
    ll ans = 0;
    // cout << a << " " << b << "\n";
    for(int i = b-1; i < w; i++){
        cout << a-1 << " " << i << ": " << choose(a-1+i, a-1) << "\n"; 
        ans = (ans+choose(a-1+i, a-1))%mod;
    }
    h = h-a;
    w = w-b;
    cout << h << " " << w << "\n";
    ans = (ans+choose(h+w, h))%mod;
    cout << ans << "\n";
    return 0;
}
