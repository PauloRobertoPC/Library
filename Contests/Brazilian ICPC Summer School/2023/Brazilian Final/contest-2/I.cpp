#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int t; cin >> t;
    while(t--){
        ll a, b, k;
        cin >> a >> b >> k;
        cout << (a-b)*(k/2) + a*(k%2==1) << "\n";
    }
    return 0;
}
// Description: Adhoc - Easy
