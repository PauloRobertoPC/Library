#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        for(int i = 0; s.size()-i-1 > i && s[i] != s[s.size()-i-1]; i++) n -= 2;
        cout << n << "\n";
    }
    return 0;
}
