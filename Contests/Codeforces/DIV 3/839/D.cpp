#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n), df(n-1);
        for(int &x:v) cin >> x;
        for(int i = 0; i+1 < n; i++) df[i] = v[i+1] - v[i];
        // for(int i = 0; i+1 < n; i++) cout << df[i] << " "; cout << "\n";
        int mmin = 1e9+10, mmax = -1;
        for(int i = 0; i+1 < n; i++){
            if(df[i] > 0) mmin = min(mmin, v[i]+df[i]/2);
            else if(df[i] < 0) mmax = max(mmax, v[i+1]+(-df[i]+1)/2);
        }
        if(mmax > mmin)
            cout << "-1\n";
        else
            cout << max(mmax, 0) << "\n";
    }
    return 0;
}
