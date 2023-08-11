#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    set<int> cj;
    vector<int> ans(n, 0);
    vector<array<int, 3>> events;
    for(int i = 1; i <= n+1; i++) cj.insert(i);
    for(int i = 0, a, b; i < n; i++){
        cin >> a >> b;
        events.push_back({a, 0, i});
        events.push_back({b, 1, i});
    }
    sort(events.begin(), events.end());
    for(auto [t, op, id]:events){
        if(op){
            cj.insert(ans[id]);
        }else{
            ans[id] = *cj.begin();
            cj.erase(cj.begin());
        }
    }
    cout << *max_element(ans.begin(), ans.end()) << "\n";
    for(int r:ans) cout << r << " "; cout << "\n";
    return 0;
}
