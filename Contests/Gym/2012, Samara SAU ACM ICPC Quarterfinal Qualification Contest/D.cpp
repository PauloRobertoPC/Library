#include <bits/stdc++.h>

using namespace std;

#define maxn int(1e6+10)

int dp[maxn];

vector<int> divisors(int num){
    int lim = sqrt(num);
    vector<int> ans = {num};
    for(int i = 2; i <= lim; i++){
        if(num%i == 0){
            ans.emplace_back(i); 
            if((num/i) != i) ans.emplace_back(num/i); 
        }
    }
    return ans;
}

int solve(int num){
    if(num == 1) return 1;
    int &ans = dp[num];
    if(ans != -1) return ans;
    vector<int> divi = divisors(num);
    ans = 0;
    for(int d:divi)
        ans += solve(num/d); 
    return ans;
}

int main(){
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    cout << solve(n) << "\n";
    return 0;
}
