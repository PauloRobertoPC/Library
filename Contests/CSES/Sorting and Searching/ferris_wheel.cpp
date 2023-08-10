#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x; cin >> n >> x;
    vector<int> v(n);
    for(int &x:v) cin >> x;
    sort(v.begin(), v.end());
    int ans = 0;
    for(int l = 0, r = n-1; l <= r; ++ans){
        if(v[l]+v[r] <= x) ++l, --r; 
        else if(v[r] <= x) --r;
        else --r, --ans;
    }
    cout << ans << "\n";
    return 0;
}
