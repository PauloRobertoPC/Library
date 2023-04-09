#include <bits/stdc++.h>

using namespace std;

string query(int i, int j){
    string s;
    if(j < i) return "present";
    cout << "? " << i << " " << j+1 << endl;
    cin >> s;
    return s;
}

int main(){
    int n; cin >> n;
    vector<int> lim(n, -1);
    int ans = 0;
    int l = 0, r = 0;
    while(l < n){
        ++l;
        if(r == n) --r;
        while(r < n && query(l-1, r) == "present") r++;
        lim[l-1] = r;
    }
    vector<int> dp(n+1, 0);
    for(int i = n-1; i >= 0; i--){
        if(lim[i] == -1) continue;
        for(int j = lim[i]; j < n; j++){
            if(dp[j+1] != 0 || j+1 == n)
                dp[i] = max(dp[i], 1+dp[j+1]);
        }
    }
    //ATCG
    cout << "! " << dp[0] << endl;
    return 0;
}
