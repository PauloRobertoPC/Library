#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for(auto &[b, a]:v) cin >> a >> b;
    sort(v.begin(), v.end());
    int b = -1, ans = 0;
    for(auto [r, l]:v){
        if(l >= b){
            b = r; 
            ++ans;
        }
    }
    cout << ans << "\n";
    return 0;
}
