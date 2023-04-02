#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> v(n);
    for(ll &x:v) cin >> x;
    sort(v.rbegin(), v.rend());
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll ans = 0;
    for(ll i = n-1; i >= 0; i--){
        if(k){
            pq.push(v[i]);
            ans += v[i];
            --k; 
        }else{
            ll aux = pq.top(); pq.pop(); pq.push(aux+v[i]);
            ans += aux+v[i];
        }
    }
    cout << ans << "\n";
    return 0;
}
