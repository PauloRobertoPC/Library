#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        for(int &x:v) cin >> x;
        int mmax = 0;
        for(int i = 0, j = 0; i < n; i = j){
            if(v[i] == 1){
                j++;
                continue;
            }
            j = i;
            while(j < n && !v[j]) j++;
            // cout << j << " " << i << "\n";
            mmax = max(mmax, j-i);
        }
        cout << mmax << "\n";
    }
    return 0;
}
