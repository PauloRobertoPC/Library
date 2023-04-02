#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<char, int> a, b;
        string s; cin >> s;
        ++a[s[0]];
        for(int i = 1; i < n; i++) ++b[s[i]];
        int ans = a.size() + b.size();
        for(int i = 1; i < n; i++){
            ++a[s[i]];
            --b[s[i]];
            if(b[s[i]] == 0) b.erase(s[i]);
            ans = max(ans, int(a.size()+b.size()));
        }
        cout << ans << "\n";
    }
    return 0;
}
