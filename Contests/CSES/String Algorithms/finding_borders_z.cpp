#include <bits/stdc++.h>

using namespace std;

vector<int> Z(string &s){
    vector<int> z(s.size(), 0);
    for(int l = 1, r = 1, i = 1; i < s.size(); i++){
        if(i > r) l = r = i;
        z[i] = min(z[i-l], r-i);
        while(i+z[i] < s.size() && s[i+z[i]] == s[z[i]]){
            ++z[i];
            l = i;
            r = i+z[i];
        }
    }
    return z;
}

int main(){
    string s; cin >> s;
    auto z = Z(s);
    for(int i = s.size()-1; i >= 0; i--)
        if(i+z[i] == s.size())
            cout << s.size()-i << " ";
    cout << "\n";
    return 0;
}
