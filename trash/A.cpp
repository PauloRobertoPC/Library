#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int, int>> e;
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        e.emplace_back(x1, 0, y1, y2);
        e.emplace_back(x2, 2, y1, y2);
    }
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        e.emplace_back(x, 1, y, y);
    }
    int ans = 0;
    set<pair<int, int>> cj;
    sort(e.begin(), e.end());
    for(auto &[x, t, y1, y2]:e){
        if(!t){
            cj.emplace(y1, y2);
        }else if(t == 1){
            auto it = cj.upper_bound({y1+1, 0});
            if(it == cj.begin()) continue;
            --it;
            if(it->first <= y1 && y1 <= it->second) ++ans;
        }else{
            cj.erase({y1, y2});
        }
    }
    cout << ans << "\n";
    return 0;
}
