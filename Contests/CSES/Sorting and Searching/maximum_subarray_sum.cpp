#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n, mmax = 0, sum = 0; 
    cin >> n;
    vector<ll> v(n);
    for(ll &x:v) cin >> x;
    for(ll i = 0; i < n; i++){
        sum = (sum+v[i] < 0 ? 0 : sum+v[i]);
        mmax = max(mmax, sum);
    }
    if(!mmax)
        mmax = *max_element(v.begin(), v.end());
    cout << mmax << "\n";
    return 0;
}
