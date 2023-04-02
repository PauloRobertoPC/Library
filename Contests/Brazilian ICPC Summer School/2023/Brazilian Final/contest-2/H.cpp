#include <bits/stdc++.h>

using namespace std;

#define INF ll(1e12)

typedef long long ll;

int main(){
    int n; cin >> n;
    ll M1 = -INF, m1 = INF, M2 = -INF, m2 = INF;
    while(n--){
        ll x, y; cin >> x >> y;
        M1 = max(M1, x+y);                
        M2 = max(M2, x-y);                
        m1 = min(m1, x+y);
        m2 = min(m2, x-y);
    }
    cout << max(M1-m1, M2-m2) << "\n";
    return 0;
}
// Description: Math - Developing the formula
