#include <bits/stdc++.h>

using namespace std;

#define maxn int(2e5+10)

string s;
int dp[maxn][3], pos = -1;

bool solve(int l, int sft){
    int r = s.size()-l-1-(sft==2);
    l += (sft == 1);
    if(r < l) return sft != 0;
    int &ans = dp[l][sft];
    if(ans != -1) return ans;
    ans = 0;
    if(sft == 0){
        if(solve(l, 1)){
            ans = true;
            pos = l;
        }
        if(solve(l, 2)){
            ans = true;
            pos = r;
        }
    }
    if(s[l] != s[r]){
        return ans;
    }
    return ans = max(bool(ans), solve(l+1, sft));
}

int main(){
    cin >> s; 
    memset(dp, -1, sizeof(dp));
    bool ok = solve(0, 0);
    cout << (ok ? "YES" : "NO") << "\n";
    if(ok) cout << pos+1 << "\n";
    return 0;
}
