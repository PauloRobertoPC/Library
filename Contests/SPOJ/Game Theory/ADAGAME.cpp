#include <bits/stdc++.h>

using namespace std;

int x, k;
string s;
int dp[10001][101], pot[4];

int get_next(int num, int d){
    int digit = (num/pot[d])%10; 
    return (digit == 9 ? num-9*pot[d] : num+pot[d]);
}

int solve(int num, int op){
    if(op == k+1) return (num > x);
    int &val = dp[num][op];
    if(val != -1) return val;
    int d0 = solve(get_next(num, 0), op+1);
    int d1 = solve(get_next(num, 1), op+1);
    int d2 = solve(get_next(num, 2), op+1);
    int d3 = solve(get_next(num, 3), op+1);
    int mmax = max({d0, d1, d2, d3});
    int mmin = min({d0, d1, d2, d3});
    return val = (op&1 ? mmax : mmin);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    pot[0] = 1;
    for(int i = 1; i < 4; i++) pot[i] = pot[i-1]*10;
    int t; cin >> t;
    while(t--){
        cin >> x >> k;
        memset(dp, -1, sizeof(dp));
        cout << (solve(x, 1) ? "Ada" : "Vinit") << "\n";   
    }
    return 0;
}
// Description: DP - Digit DP and Simple Game Theory
