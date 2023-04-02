#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n, m; cin >> n >> m;        
    ll sum1 = 0, sum2 = 0;
    vector<array<ll, 3>> v(n);     
    for(ll i = 0; i < n; i++){
        cin >> v[i][1] >> v[i][2];
        v[i][0] = v[i][1] - v[i][2];
        sum1 += v[i][1];
        sum2 += v[i][2];
    }
    if(sum2 > m){
        cout << "-1\n";
        return 0;
    }
    sort(v.rbegin(), v.rend()); 
    ll i;
    for(i = 0; i < n && sum1 > m; i++) sum1 -= v[i][0];
    cout << i << "\n";
    return 0;
}
// Description: Greedy(Easy)

