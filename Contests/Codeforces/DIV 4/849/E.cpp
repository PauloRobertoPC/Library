#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> v;
vector<vector<ll>> dp;

ll solve(ll pos, ll direction){
    if(pos >= v.size()) return 0;
    if(pos == v.size()-1) return v[pos]*(direction == 0 ? 1 : -1);
    ll &val = dp[pos][direction];
    if(val != -1) return val;
    if(direction){
        val = -v[pos]+v[pos+1]+solve(pos+2, 0);
        val = max(val, v[pos]-v[pos+1]+solve(pos+2, 0));
        if(pos+1 < v.size()-1){
            val = max(val, v[pos]+v[pos+1]+solve(pos+2, 1));
            val = max(val, -v[pos]-v[pos+1]+solve(pos+2, 1));
        }
    }else{
        val = v[pos]+v[pos+1]+solve(pos+2, 0);
        val = max(val, -v[pos]-v[pos+1]+solve(pos+2, 0));
        if(pos+1 < v.size()-1){
            val = max(val, -v[pos]+v[pos+1]+solve(pos+2, 1));
            val = max(val, v[pos]-v[pos+1]+solve(pos+2, 1));
        }
    }
    return val;
}

int main(){
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        v.assign(n, 0);
        dp.assign(n, vector<ll>(2, -1));
        for(ll &x:v) cin >> x;
        cout << solve(0, 0) << "\n";
    }
    return 0;
}
