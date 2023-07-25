#include <bits/stdc++.h>

using namespace std;

vector<int> Z(string &s){
    vector<int> z(s.size(), 0);
    for(int l = 0, r = 0, i = 1; i < s.size(); i++){
        if(i > r) l = r = i;
        z[i] = min(z[i-l], r-i);
        while(i+z[i] < s.size() && s[i+z[i]] == s[z[i]]){
            ++z[i];
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main(){
    string s, t; cin >> s >> t;
    string aux = t + '$' + s;
    auto z = Z(aux);
    int ans = 0;
    for(int i = t.size()+1; i < z.size(); i++)
        ans += (z[i] == t.size());
    cout << ans << "\n";
    return 0;
}
