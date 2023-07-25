#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n); 
        for(int &x:v) cin >> x;
        int mmin = *min_element(v.begin(), v.end());
        int mmax = *max_element(v.begin(), v.end());
        int resp = 10000000;
        for(int i = 1; i <= 100; i++){
            int ans = 0;
            if(mmin < i) ans += 2*abs(i-mmin);
            if(mmax > i) ans += 2*abs(i-mmax);
            resp = min(resp, ans);
        }
        cout << resp << "\n";
    }
    return 0;
}
