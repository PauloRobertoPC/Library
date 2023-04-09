#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; string s;
        cin >> n >> s;
        bool ok = true;
        for(int i = 0, p = 0; i < n; i++, p^=1){
            if(p){
                if(i+1 >= n || s[i] != s[i+1]) ok = false;
                i++;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
