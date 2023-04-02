#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n, ans = 0; cin >> n;
    while(n--){
        ll t, d; cin >> t >> d;
        if(t >= ans) ans = t+d;
        else ans += d;
    }
    cout << ans << "\n";
    return 0;
}
