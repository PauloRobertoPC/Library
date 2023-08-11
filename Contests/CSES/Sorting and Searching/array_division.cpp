#include <bits/stdc++.h>

using namespace std;

#define maxn ll(2e5+10)

typedef long long ll;

ll n, k;
ll v[maxn];

bool ok(ll sum){
    ll aux = k, tot = 0;
    for(ll i = 0; i < n; i++){
        if(v[i] > sum) return false;
        if(tot+v[i] > sum){
            --aux;
            tot = v[i];
        }else{
            tot += v[i];
        }
    }
    aux -= (tot != 0);
    return aux >= 0;
}

ll bb(){
    ll l = -1, r = 1e15, mid;
    while(l < r-1){
        mid = (l+r)/2;
        if(ok(mid)) r = mid;
        else l = mid;
    }
    return r;
}

int main(){
    cin >> n >> k;
    for(ll i = 0; i < n; i++) cin >> v[i];
    cout << bb() << "\n";
    return 0;
}
