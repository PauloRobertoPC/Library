#include <bits/stdc++.h>

using namespace std;

bool ok(int a, int b){
    if(b > a) swap(a, b);
    int diff = a-b;
    int aa = a-2*diff, bb = b-diff;
    return ((a == 2*b || (a == b && a%3 == 0) || (aa >= 0 && bb >= 0 && aa == bb && aa%3 == 0)));
}

int main(){
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        cout << (ok(a, b) ? "YES" : "NO") << "\n";
    }
    return 0;
}
