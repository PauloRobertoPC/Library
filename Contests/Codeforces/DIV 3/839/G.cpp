#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> v(n);
        for(int &x:v) cin >> x;
        sort(v.begin(), v.end());
        bool ok = true;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(x >= y) continue;
            if(x >= v[i]){
                ++x;
                ++ans;
                continue;
            }
            int ciclo = i-(n-i);
            if(ciclo <= 0){
                ok = false;
                break;
            }
            x -= (n-i);
            ans += (n-i);
            int d = v[i]-x-i; 
            int tot_c = d/ciclo;
            // cout << v[i] << " " << ciclo << " " << x << " " << ans << " ";
            // cout << d << " " << tot_c << "\n";
            ans += n*tot_c+i+1;
            x += tot_c*ciclo+i+1;
            // cout << ans << " " << x << "\n";
        }
        if(!ok)
            ans = -1;
        cout << ans << "\n";
    }
    return 0;
}
