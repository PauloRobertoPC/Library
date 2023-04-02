#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        bool ok = false;
        int a, b, c, d; cin >> a >> b >> c >> d;
        for(int i = 0; i < 5; i++){
            int aa = a, bb = b, cc = c, dd = d;
            tie(a, b, c, d) = {cc, aa, dd, bb};
            ok |= (a < b && c < d && a < c && b < d);
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
