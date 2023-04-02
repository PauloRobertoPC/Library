#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s; 
        cin >> s;
        map<char, int> mp;
        for(auto ch:s) ++mp[ch];
        int ans = 0;
        for(int i = 0; i < 26; i++){
            int mmin = min(mp[i+'a'], mp[i+'A']); 
            mp[i+'a'] -= mmin;
            mp[i+'A'] -= mmin;
            ans += mmin;
        }
        for(int i = 0; i < 26; i++){
            if(k == 0) break;
            int ok = mp[i+'a']/2; 
            // cout << min(ok, k) << " " << char(i+'a') << " " << k << "\n";
            ans += min(ok, k);
            k -= min(ok, k);
            ok = mp[i+'A']/2; 
            // cout << min(ok, k) << " " << char(i+'A') << " " << k << "\n";
            ans += min(ok, k);
            k -= min(ok, k);
        }
        cout << ans << "\n";
    }
    return 0;
}
