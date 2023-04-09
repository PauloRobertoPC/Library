#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll w, h;
map<pair<ll, ll>, bool> mp;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

bool query(ll i, ll j){
    if(mp.count({i, j})) return mp[{i, j}];
    cout << "? " << i << " " << j << endl;
    string s; cin >> s;
    return mp[{i, j}] = (s[0] == 'b');
}

ll bb(ll pos, ll mmin){
    ll l = 1, r = h+1, mid;
    while(l < r-1){
        mid = (l+r)/2;
        if(query(pos, mid))
            l = mid;
        else
            r = mid;
    }
    return l;
}

int main(){
    cin >> w >> h;
    vector<ll> ord(w);
    iota(ord.begin(), ord.end(), 1);
    shuffle(ord.begin(), ord.end(), rng);
    ll ans = 0, best = 1;
    for(ll x:ord){
        if(query(x, ans+1)) ans = bb(x, ans+1), best = x;
        if(ans == h) break;
    }
    cout << "! " << best << " " << ans << endl;
    return 0;
}
