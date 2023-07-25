#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    while(n--){
        map<string, int> mapa;
        int m; cin >> m;
        vector<string> v(m);
        for(auto &s:v){
            cin >> s;
            for(int i = 1; i <= s.size(); i++)
                ++mapa[s.substr(0, i)];
        }
        bool ok = false;
        for(auto &s:v)
            ok |= (mapa[s] >= 2);
        cout << (ok ? "NO" : "YES") << "\n";
    }
    return 0;
}
