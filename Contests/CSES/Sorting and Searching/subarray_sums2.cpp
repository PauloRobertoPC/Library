#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    map<ll, ll> freq; freq[0] = 1;
    ll n, k, sum = 0, ans = 0; cin >> n >> k;
    vector<ll> v(n);
    for(ll &x:v){
        cin >> x;
        sum += x;
        ans += freq[sum-k];
        ++freq[sum];
    }
    cout << ans << "\n";
    return 0;
}
