#include <bits/stdc++.h>

using namespace std;

int main(){
    int tot; cin >> tot;
    vector<int> v(3);
    for(int &x:v) cin >> x;
    sort(v.begin(), v.end());
    int ans = 0;
    for(int x:v){
        if(tot >= x){
            tot -= x;
            ++ans;
        }
    }
    cout << ans << "\n";
    return 0;
}
