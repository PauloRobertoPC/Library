#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string s, r = "codeforces"; cin >> s;
        int ans = 0;
        for(int i = 0; i < 10; i++) ans += (s[i] != r[i]);
        cout << ans << "\n";
    }
    return 0;
}
