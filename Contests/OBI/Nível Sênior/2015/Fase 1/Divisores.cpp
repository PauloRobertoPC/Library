#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; 
    cin >> n;
    int lim = sqrt(n);
    int ans = 0;
    for(int i = 1; i <= lim; i++)
        if(n%i == 0)
            ans += ((i == (n/i)) ? 1 : 2);
    cout << ans << "\n";
    return 0;
}
