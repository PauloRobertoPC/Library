#include <bits/stdc++.h>

using namespace std;

pair<int, int> normalize(int x, int y){
    int gcd = __gcd(x, y);
    y /= gcd;
    x /= gcd;
    if(y < 0) y = -y, x = -x;
    else if(y == 0) x = abs(x);
    return {x, y};
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<tuple<int, int, int, int>> v(n);
        map<pair<int, int>, set<int>> ang;
        for(auto &[x1, y1, x2, y2]:v){
            cin >> x1 >> y1 >> x2 >> y2;
            int y = y2-y1;
            int x = x2-x1;
            tie(x, y) = normalize(x, y);
            ang[{x, y}].emplace(x1*y-y1*x);
        }
        long long ans = 0;
        for(auto par:ang){
            int x = par.first.second;
            int y = -par.first.first;
            tie(x, y) = normalize(x, y);
            ans += ang[{x, y}].size()*ang[{par.first.first, par.first.second}].size();
        }
        cout << ans/2 << "\n";
    }
    return 0;
}
// Description: Geometry - Angular Coeficient + Cross Product
