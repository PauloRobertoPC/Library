#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll calc(vector<pair<ll, ll>> &v){
    ll ans = 0, t = 0;
    for(auto [duration, polls]:v){
        ans += polls-t;
        t += duration;
    }
    return ans;
}

int main(){
    ll n; cin >> n;
    vector<pair<ll, ll>> v(n);
    for(ll i = 0, a, b; i < n; i++){
        cin >> a >> b;
        v[i] = {a, b-a};
    }
    sort(v.begin(), v.end());
    cout << calc(v) << "\n";
    return 0;
}
