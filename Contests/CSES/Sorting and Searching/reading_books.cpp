#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n, sum = 0; cin >> n;
    vector<ll> v(n);
    for(ll &x:v) cin >> x, sum += x;
    cout << max(sum, *max_element(v.begin(), v.end())*2) << "\n";
    return 0;
}
