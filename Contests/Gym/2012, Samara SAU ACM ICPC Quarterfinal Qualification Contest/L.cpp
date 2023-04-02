#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<long long> v(n);
    for(auto &x:v) cin >> x;
    cout << v[0] << " ";
    for(int i = 1; i < n; i++) cout << (v[i] - v[i-1]) << " ";
    cout << "\n";
    return 0;
}
