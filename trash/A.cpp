#include <bits/stdc++.h>

using namespace std;

string s;

vector<int> Z(){
    vector<int> z(s.size(), 0);
    for(int l = 1, r = 1, i = 1; i < s.size(); i++){
        if(i > r) l = r = i;
        z[i] = min(z[i-l], r-i);
        while(i+z[i] < s.size() && s[z[i]] == s[i+z[i]]){
            ++z[i];
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main(){
    cin >> s;
    auto z = Z();
    set<int> cj;
    int mmax = 0;
    for(int i = 0; i < s.size(); i++){
        int m = (z[i]+i == s.size() ? 1 : 0);
        mmax = max(mmax, z[i]-m);
    }
    int ans = 0;
    for(int l = 0, r = s.size()-1; r >= 0; l++, --r){
        if(z[r]+r != s.size()) continue;
        if(mmax >= l+1)
            ans = l+1;
    }
    cout << (ans == 0 ? "Just a legend" : s.substr(0, ans)) << "\n";
    return 0;
}
