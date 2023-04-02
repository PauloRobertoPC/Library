#include <bits/stdc++.h>

using namespace std;

int main(){
    string s = "codeforces";
    set<char> cj;
    for(auto ch:s) cj.insert(ch);
    int n; cin >> n;
    while(n--){
        char ch; cin >> ch;
        cout << (cj.count(ch) ? "YES" : "NO") << "\n";
    }
    return 0;
}
