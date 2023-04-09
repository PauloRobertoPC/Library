#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<tuple<int, int, int, int>> e;
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        e.emplace_back(x1, 0, y2, y1);
        e.emplace_back(x2, 1, y2, y1);
    }
    int ans = n;
    set<pair<int, int>> cj, used;
    sort(e.begin(), e.end());
    for(auto &[x, t, y1, y2]:e){
        if(t){
            cj.erase({y1, y2});
            used.erase({y1, y2});
        }else{
            auto it = cj.upper_bound({y1+1, 0});  
            if(it != cj.begin()){
                --it;
                if(it->first < y1 && it->second > y1 && !used.count({it->first, it->second})){
                    used.emplace(it->first, it->second);
                    --ans; 
                }
            }
            cj.emplace(y1, y2); 
        }
    }
    cout << ans << "\n";
    return 0;
}

// Description: Geometry - Line Sweep
