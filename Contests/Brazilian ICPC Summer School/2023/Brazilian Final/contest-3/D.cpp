#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int mmin = min(n-i, n-j)+1;
                ans += mmin;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
// Description: Math - Easy Count
