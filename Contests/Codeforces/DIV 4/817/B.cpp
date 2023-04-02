#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s, t; cin >> s >> t;
        for(int i = 0; i < n; i++){
            if(s[i] == 'G') s[i] = 'B';
            if(t[i] == 'G') t[i] = 'B';
        }
         
        cout << (s == t ? "YES" : "NO") << "\n";
    }
    return 0;
}
