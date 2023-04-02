#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int i = 0, a = 0, b = 0;
        for(; i < s.size() && s[i] != '+'; i++) a += (s[i]-'0');
        ++i;
        for(; i < s.size() && s[i] != '+'; i++) b += (s[i]-'0');
        cout << a+b << "\n";
    }
    return 0;
}
