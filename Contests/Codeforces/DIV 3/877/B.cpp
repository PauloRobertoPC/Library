#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        b = min(30, b);
        cout << min(a+1, 1<<b) << "\n";
    }
    return 0;
}
