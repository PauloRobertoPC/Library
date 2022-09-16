#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; string s; cin >> n >> s;
        for(int i = 0; i < n; i++){
            int j;
            if(i+2 < n && s[i+2] == '0' && (i+3 >= n || s[i+3] != '0')){
                j = 10*int(s[i]-'0') + int(s[i+1]-'0');
                i += 2;
            }else{
                j = int(s[i]-'0');
            }
            // cout << j << " ";
            cout << char('a'+j-1);
        }
        cout << "\n";
    }
    return 0;
}
