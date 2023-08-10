#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    long long ans = 0;
    for(long long mult = 5; mult <= n; mult *= 5)
        ans += (n/mult);
    cout << ans << "\n";
    return 0;
}
