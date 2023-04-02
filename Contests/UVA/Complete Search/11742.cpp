#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m; 
    while(cin >> n >> m){
        if(!n && !m) break;
        vector<tuple<int, int, int>> r(m);
        for(auto &[a, b, c]:r) cin >> a >> b >> c;
        vector<int> v(n);
        iota(v.begin(), v.end(), 0);
        int ans = 0;
        do{
            vector<int> pos(n);
            for(int i = 0; i < n; i++) pos[v[i]] = i;
            int tot = 0;
            for(auto [a, b, c]:r){
                int d = abs(pos[a]-pos[b]);     
                tot += (c > 0 ? d <= c : d >= -c);
            }
            ans += (tot == m);
        }while(next_permutation(v.begin(), v.end()));
        cout << ans << "\n";
    }
    return 0;
}
