#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    map<ll, ll> freq; freq[0] = 1;
    ll n, sum = 0, ans = 0; cin >> n;
    vector<ll> v(n);
    for(ll &x:v){
        cin >> x;
        sum = (((sum+x)%n)+n)%n;
        ans += freq[sum];
        ++freq[sum];
    }
    cout << ans << "\n";
    return 0;
}
