#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        vector<string> ans;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0') continue; 
            ans.emplace_back(s[i]+string(s.size()-i-1, '0'));
        }
        cout << ans.size() << "\n";
        for(auto ss:ans) cout << ss << " "; cout << "\n";
    }
    return 0;
}
