#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<int, int> f;
        for(int i = 0, num; i < n; i++) cin >> num, ++f[num];
        int ans = 0;
        while(f.size()){
            int i = f.begin()->first;
            for(; f.count(i); i++){
                --f[i];
                if(!f[i]) f.erase(i);
            }
            ++ans;
        }
        cout << ans << "\n";
    }
    return 0;
}
