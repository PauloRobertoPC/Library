#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> v(n);
    for(ll &x:v) cin >> x;
    map<ll, ll> sum;
    sum[v[0]] = 0;
    for(ll i = 1; i < n; i++){
        for(ll j = i+1; j < n; j++){
            ll aux = k-v[i]-v[j];
            if(sum.count(aux)){
                cout << sum[aux]+1 << " " << i+1 << " " << j+1 << "\n";
                return 0;
            }
        }
        sum[v[i]] = i;
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
