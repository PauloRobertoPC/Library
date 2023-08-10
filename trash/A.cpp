#include <bits/stdc++.h>

using namespace std;

int main(){
    int k, n, w;
    cin >> k >> n >> w;
    n = -n;
    for(int i = 1; i <= w; i++) n += i*k;
    cout << max(0, n) << "\n";
    return 0;
}
