#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k, q;
        long long ans = 0;
        cin >> n >> k >> q;
        vector<int> v(n);
        for(int &x:v) cin >> x;
        for(int i = 0, j; i < n; i = j){
            j = i;
            if(v[i] > q){
                j++;
                continue;
            }
            int cnt = 1;
            while(j < n && v[j] <= q){
                if(j-i+1 >= k){
                    ans += cnt++;
                }
                j++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
