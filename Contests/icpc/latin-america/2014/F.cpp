#include <bits/stdc++.h>

using namespace std;

int main(){
    int m, n; cin >> m >> n;
    vector<tuple<int, int, int, int>> p;
    int a, b, c, d;
    for(int i = 0; i < m; i++) cin >> a >> b >> c >> d, p.emplace_back(a, b, c, d);
    int x, y, z;
    map<vector<bool>, int> f;
    for(int i = 0; i < n; i++){
        cin >> x >> y >> z;
        int cnt = 0; vector<bool> bt(m); 
        for(auto [a, b, c, d]:p) bt[cnt++] = (x*a+y*b+z*c < d); 
        ++f[bt];
    }
    int mmax = 0;
    for(auto par:f) mmax = max(mmax, par.second);
    cout << mmax << "\n";
    return 0;
}
