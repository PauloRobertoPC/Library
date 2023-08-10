#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n; cin >> n;
    ll sum = ((n+1)*n)/2;
    if(sum&1){
        cout << "NO\n";
        return 0;
    }
    ll half = sum/2;
    set<ll> cj;
    for(ll i = n; i >= 1 && half; i--){
        if(half >= i){
            half -= i;
            cj.insert(i);
        }
    }
    if(half){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    cout << cj.size() << "\n"; 
    for(ll x:cj) cout << x << " "; cout << "\n";
    cout << (n-cj.size()) << "\n";
    for(ll i = 1; i <= n; i++) if(!cj.count(i)) cout << i << " "; cout << "\n";

    return 0;
}
