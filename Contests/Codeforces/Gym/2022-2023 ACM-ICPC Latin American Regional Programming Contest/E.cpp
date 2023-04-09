#include <bits/stdc++.h>

using namespace std;

vector<int> v;
vector<vector<vector<int>>> dp;

int solve(int a, int b, int id){
    if(a < 0 || b < 0) return 100000;
    if(id == v.size()) return a+b;
    if(dp[a][b][id] != -1) return dp[a][b][id];
    return dp[a][b][id] = min({
        solve(a-v[id], b, id+1),
        solve(a, b-v[id], id+1),
        solve(a, b, id+1)
    });
}

int main(){
    int n, k, e;
    cin >> n >> k >> e;
    int sum2 = n-k-e; 
    for(int i = 1; i <= n; i++)
        if(i != k)
            v.emplace_back(i);
    if(e <= 10 || sum2 <= 10){
        dp.assign(e+1, vector<vector<int>>(sum2+1, vector<int>(v.size()+1, -1)));
        cout << solve(e, sum2, 0) << "\n";
    }else{
        cout << "0\n";
    }
    return 0;
}
