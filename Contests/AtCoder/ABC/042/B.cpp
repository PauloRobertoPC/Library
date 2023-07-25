#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, l;
    cin >> n >> l;
    vector<string> v(n);
    for(auto &x:v) cin >> x;
    sort(v.begin(), v.end());
    for(auto x:v) cout << x;
    cout << "\n";
    return 0;
}
