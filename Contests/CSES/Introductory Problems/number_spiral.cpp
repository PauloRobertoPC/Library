#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// 2 + 4 + 6 + 8 + 10 + ...
ll pa(ll diagonal){
    return (diagonal+1)*diagonal;
}

int main(){
    ll t; cin >> t;
    while(t--){
        ll x, y; cin >> x >> y;
        ll diagonal = max(x, y);
        ll num_diagonal = 1 + pa(diagonal-1);
        ll dist = abs(min(x, y) - diagonal);
        ll num = num_diagonal;
        if(diagonal&1){
            if(x != diagonal) num += dist;
            else num -= dist;
        }else{
            if(x != diagonal) num -= dist;
            else num += dist;
        }
        cout << num << "\n";
    }
    return 0;
}
