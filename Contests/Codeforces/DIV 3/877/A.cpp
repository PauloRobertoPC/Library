#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; 
    cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        string t = "";
        for(int i = 0, j; i < s.size(); i = j){
            t += s[i];
            j = i+1;
            while(j < s.size() && s[j] != s[i]) ++j;
            ++j;
        }
        cout << t << "\n";
    }
    return 0;
}
