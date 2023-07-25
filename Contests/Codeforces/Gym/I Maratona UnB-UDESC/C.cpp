#include <bits/stdc++.h>

using namespace std;

int dp[1010];
int pref[1010];

int main(){
    int n; cin >> n;
    dp[0] = dp[1] = pref[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = i; j > i-j; j--){
            cout << i << " -> " << j << " " << i-j << ": " << pref[i-j] << "\n";
            if(j&1)
                dp[i] += dp[i-j];
        }
        pref[i] = pref[i-1] + dp[i];
    }
    for(int i = 1; i <= n; i++){
        cout << i << " " << dp[i] << "\n";
    }
    cout << dp[n] << "\n";
    return 0;
}
