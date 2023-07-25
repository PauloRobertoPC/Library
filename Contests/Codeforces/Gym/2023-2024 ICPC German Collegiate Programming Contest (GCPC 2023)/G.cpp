#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n; cin >> n;
    vector<ll> t = {0};
    ll acm = 1;
    for(ll i = 1; i < 10; i++){
        for(ll j = 1; j <= 9; j++){
            string s = string(i, char('0'+j));
            t.push_back(stoll(s));
        }
        acm *= 10;
        if(acm >= 100)
            t.push_back(acm);
    }
    int ans = 0;
    for(auto x:t) ans += (n >= x);
    cout << ans << "\n";
    return 0;
}
