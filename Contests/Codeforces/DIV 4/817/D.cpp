#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        string s; cin >> s;
        ll sum = 0;
        vector<pair<ll, ll>> changes;
        for(ll i = 0; i < n; i++){
            ll l = i;
            ll r = n-i-1;
            if(s[i] == 'L'){
                sum += l;
                changes.emplace_back(r, l);
            }else{
                changes.emplace_back(l, r);
                sum += r;
            }
        }
        sort(changes.rbegin(), changes.rend());
        for(ll i = 0; i < n; i++){
            if(changes[i].first > changes[i].second)
                sum += changes[i].first - changes[i].second;
            cout << sum << " ";
        }
        cout << "\n";
    }
    return 0;
}
