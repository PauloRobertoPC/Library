#include <bits/stdc++.h>

using namespace std;

#define maxn int(2e5+1)

int n;
string a, b, c;

int dp[maxn][2][2][2];

int solve(int pos, int ua, int ub, int uc){
    if(pos == n) return 1;
    int &ans = dp[pos][ua][ub][uc];
    if(ans != -1) return ans;
    ans = 0;
    for(char ch = 'a'; ch <= 'z'; ch++){
        int ea = (a[pos]!=ch), eb = (b[pos]!=ch), ec = (c[pos]!=ch); 
        if(ea+ua == 2 || eb+ub == 2 || ec+uc == 2) continue;
        ans += solve(pos+1, max(ea, ua), max(eb, ub), max(ec, uc));
        ans = min(ans, 2);
    }
    return ans;
}

int main(){
    cin >> a >> b >> c; 
    n = a.size();
    memset(dp, -1, sizeof(dp));
    int ans = solve(0, 0, 0, 0);
    if(!ans){
        cout << "Impossible\n";
    }else if(ans == 2){
        cout << "Ambiguous\n";
    }else{
        string ok = ""; 
        int pos = 0, ua = 0, ub = 0, uc = 0; 
        while(pos != n){
            int &ans = dp[pos][ua][ub][uc];
            for(char ch = 'a'; ch <= 'z'; ch++){
                int ea = (a[pos]!=ch), eb = (b[pos]!=ch), ec = (c[pos]!=ch); 
                if(ea+ua == 2 || eb+ub == 2 || ec+uc == 2) continue;
                if(ans == solve(pos+1, max(ea, ua), max(eb, ub), max(ec, uc))){
                    ok += ch; 
                    ua = max(ua, ea);
                    ub = max(ub, eb);
                    uc = max(uc, ec);
                    ++pos;
                }
            }
        }
        cout << ok << "\n";
    }
    return 0;
}
