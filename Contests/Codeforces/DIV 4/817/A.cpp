#include <bits/stdc++.h>

using namespace std;

int main(){
    string s = "Timur";
    sort(s.begin(), s.end());
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string t; cin >> t;
        sort(t.begin(), t.end());
        cout << (s == t ? "YES" : "NO") << "\n";
    }
    return 0;
}
