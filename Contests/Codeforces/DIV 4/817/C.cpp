#include <bits/stdc++.h>
#include <string>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<string, int> mp;
        vector<vector<string>> s(3, vector<string>(n));
        for(int i = 0; i < 3; i++)
            for(string &ss:s[i])
                cin >> ss, ++mp[ss];
        vector<int> ans(3, 0);
        for(int i = 0; i < 3; i++){
            for(string &ss:s[i]){
                ans[i] += (mp[ss] == 1 ? 3 : (mp[ss] == 2 ? 1 : 0));
            }
        }
        for(int i = 0; i < 3; i++) cout << ans[i] << " "; cout << "\n";
    }
    return 0;
}
