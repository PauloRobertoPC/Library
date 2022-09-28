#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

ll plant(priority_queue<ii> &pq, ll tot){
    ll ans = 0;
    while(!pq.empty() && tot){
        ii par = pq.top(); pq.pop(); 
        ll bought = min(tot, par.second);
        ans += bought*par.first;
        par.second -= bought; tot -= bought;
        if(par.second > 0) pq.push(par);
    }
    return ans;
}

void solve(){
    ll d, n, x; cin >> d >> n >> x;
    ll q, l, v;
    map<ll, vector<ii>> deadline;
    for(ll i = 0; i < n; i++){
        cin >> q >> l >> v;
        if(d-l <= 0) continue;
        deadline[-(d-l)].emplace_back(v, q);        
    }
    deadline[0].emplace_back(0, 0);        
    ll ans = 0, last_day = d-1;
    priority_queue<ii> pq;
    for(auto mp:deadline){
        ll dead = -mp.first;
        ans += plant(pq, (last_day-dead)*x);
        // cout << dead << " " << last_day << "\n";
        last_day = dead;
        for(auto par:mp.second) pq.push(par);
    }
    cout << ans << "\n";
}

int main(){
    ll t; cin >> t;
    for(ll i = 1; i <= t; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
