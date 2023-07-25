#include <bits/stdc++.h>

using namespace std;

int main(){
    int mdc = 0;
    int n, k; cin >> n >> k;
    while(n--){
        int num; cin >> num;
        mdc = __gcd(mdc, num);
    }
    cout << (k%mdc == 0 ? "YES" : "NO") << "\n";
    return 0;
}
