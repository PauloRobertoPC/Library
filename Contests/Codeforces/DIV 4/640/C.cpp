#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll bb(ll n, ll k){
    ll l = 0, r = 1e18, mid;
    while(l < r-1){
        mid = (l+r)/2;
        if(mid-mid/n < k)
            l = mid;
        else
            r = mid;
    }
    return r;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        cout << bb(n, k) << "\n"; 
    }
    return 0;
}
