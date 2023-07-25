#include <bits/stdc++.h>

using namespace std;

#define maxn ll(2e5+10)

typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll, ll> iiii;

ll n;
vector<iiii> v;
ii dp[maxn], dad[maxn];

ii solve(ll i){
    if(i >= n) return {0, 0};
    if(dp[i] != ii(-1, -1))
        return dp[i];

    ll a, b, c, d; tie(a, b, c, d) = v[i];
    auto it = lower_bound(v.begin(), v.end(), iiii(b, -1, -1, -1));
    ll can = it-v.begin();

    ii op1 = solve(i+1);
    ii op2 = solve(can);
    op2.first += c;
    op2.second -= (b-a);

    if(op2 > op1){
        dad[i] = {can, 1};
        dp[i] = op2;
    }else{
        dad[i] = {i+1, 0};
        dp[i] = op1;
    }
    return dp[i];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    v.resize(n);
    ll cnt = 1;
    for(auto &[a, b, c, d]:v)
        cin >> a >> b >> c, d = cnt++;

    sort(v.begin(), v.end());

    memset(dp, -1, sizeof(dp));
    pair<ll, ll> ans = solve(0);

    vector<ll> choosed;
    for(ll curr = 0; curr != n; curr = dad[curr].first)
        if(dad[curr].second)
            choosed.emplace_back(curr);

    cout << choosed.size() << " " << ans.first << " " << -ans.second << "\n";
    for(ll x:choosed){
        int a, b, c, d;
        tie(a, b, c, d) = v[x];
        cout << d << " ";
    }
    cout << "\n";

    return 0;
}
