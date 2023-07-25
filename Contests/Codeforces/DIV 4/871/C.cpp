#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(20, 100000000);
        for(int i = 0; i < n; i++){
            int m, num; cin >> m >> num;
            v[num] = min(v[num], m);
        }
        int ans = min(v[11], v[01]+v[10]);
        if(ans >= 100000000){
            cout << "-1\n";
        }else{
            cout << ans << "\n";
        }
        
    }
    return 0;
}
