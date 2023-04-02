#include <bits/stdc++.h>

using namespace std;

int n, a, b;

bool ok(int q){
    return q*a >= n;
}

int bb(){
    if(b < a) return 1;
    int l = 0, r = 1e7+1, mid;
    while(l < r-1){
        mid = (l+r)/2;
        if(ok(mid))
            r = mid;
        else
            l = mid;
    }
    return r;
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> a >> b;
        cout << bb() << "\n";
    }
    return 0;
}
