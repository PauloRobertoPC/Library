#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<pair<int, int>> v;
    for(int a, b; n; n--){
        cin >> a >> b;
        v.emplace_back(a, 1);
        v.emplace_back(b, -1);
    }
    sort(v.begin(), v.end());
    int aux = 0, mmax = 0;
    for(auto [t, s]:v){
        aux += s;
        mmax = max(mmax, aux);
    }
    cout << mmax << "\n";
    return 0;
}
