#include <bits/stdc++.h>
#include <string>

using namespace std;

int main(){
    string m = "meow";
    string M = "MEOW";
    int t; cin >> t;
    while(t--){
        int n; string s;
        cin >> n >> s;
        bool ok = true;
        int j = 0;
        for(int i = 0; i < 4; i++){
            int c = 0;
            while(j < n && (s[j] == m[i] || s[j] == M[i])) j++, c++;
            ok &= (c != 0);
        }
        cout << (j >= n && ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
