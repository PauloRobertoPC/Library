#include <bits/stdc++.h>

using namespace std;

int main(){
    map<char, pair<int, int>> mv;
    mv['L'] = {-1, 0};  
    mv['R'] = {1, 0};  
    mv['U'] = {0, 1};
    mv['D'] = {0, -1};
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int i = 0, j = 0;
        bool ok = false;
        for(auto ch:s){
            int x, y; tie(x, y) = mv[ch];
            i += x; j += y;
            if(i == 1 && j == 1) ok = true;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
