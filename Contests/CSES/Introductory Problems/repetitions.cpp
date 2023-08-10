#include <bits/stdc++.h>

using namespace std;

int main(){
    string s; cin >> s; 
    int n = s.size(), ans = 0;
    for(int i = 0, j; i < n; i = j){
        j = i;
        while(j < n && s[i] == s[j]) ++j;
        ans = max(ans, j-i); 
    }
    cout << ans << "\n";
    return 0;
}
