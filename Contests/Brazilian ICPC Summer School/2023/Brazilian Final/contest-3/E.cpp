#include <bits/stdc++.h>

using namespace std;

#define maxn ll(1e5+10)
#define INF ll(1e17)

typedef long long ll;

ll n; 
string s, t = "hard";
ll v[maxn], dp[maxn][4];

ll solve(ll pos, ll sft){
    if(sft == 4) return INF;
    if(pos == n) return 0;
    ll &ans = dp[pos][sft];
    if(ans != -1) return ans;
    ans = min(solve(pos+1, sft+(s[pos]==t[sft])), solve(pos+1, sft)+v[pos]); 
    return ans;
}

int main(){
    cin >> n;
    cin >> s;
    for(ll i = 0; i < n; i++) cin >> v[i];
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << "\n";
    return 0;
}
// Description: DP - Easy
