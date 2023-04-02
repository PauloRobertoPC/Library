#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll c;
vector<ll> cost, pref;
vector<vector<ll>> dp;
vector<vector<pair<ll, ll>>> dad;

ll solve(ll pos, ll cp1){
    if(pos >= cost.size()) return 0;
    ll &ans = dp[pos][cp1];
    if(ans != -1) return ans;
    ll cp2 = 2*c - cp1 - pref[pos-1];
    ans = 0;
    if(cp1 >= cost[pos] && 1+solve(pos+1, cp1-cost[pos]) > ans){
        ans = 1+solve(pos+1, cp1-cost[pos]);
        dad[pos][cp1] = {0, cp1-cost[pos]};
    }
    if(cp2 >= cost[pos] && 1+solve(pos+1, cp1) > ans){
        ans = 1+solve(pos+1, cp1);
        dad[pos][cp1] = {1, cp1};
    }
    return ans; 
}

int main(){
    ll t; cin >> t;
    while(t--){
        cin >> c; c *= 100; 
        ll cp; cost.assign(1, 0);
        while(cin >> cp, cp) cost.emplace_back(cp);
        pref.assign(cost.size(), 0);
        for(ll i = 1; i < cost.size(); i++) pref[i] = pref[i-1] + cost[i];
        dp.assign(cost.size()+1, vector<ll>(c+1, -1));
        dad.assign(cost.size()+1, vector<pair<ll, ll>>(c+1, {-1, -1}));
        ll ans = solve(1, c);
        cout << ans << "\n";
        for(int i = 1; i <= ans; i++){
            cout << (dad[i][c].first == 0 ? "port" : "starboard") << "\n";
            c = dad[i][c].second;
        }
        if(t) cout << "\n";
    }
    return 0;
}
// Description: DP with bound state
