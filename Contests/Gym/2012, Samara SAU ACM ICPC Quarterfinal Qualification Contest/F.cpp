#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, a, b, c; cin >> n;
    int num; cin >> num;
    vector<int> lvl(n+1, -1); lvl[num] = 0;
    set<tuple<int, int, int>> cj;
    cj.emplace(1, num-1, num);
    cj.emplace(num+1, n, num);
    long long ans = 0;
    for(int i = 1; i < n; i++){
        cin >> num;
        auto it = cj.upper_bound({num, -1, -1});
        if(it == cj.end()) --it;
        tie(a, b, c) = *it;
        if(a > num) --it;
        tie(a, b, c) = *it;
        cj.erase(it);
        if(a <= num-1) cj.emplace(a, num-1, num);
        if(num+1 <= b) cj.emplace(num+1, b, num);
        lvl[num] = lvl[c] + 1; 
        ans += lvl[num];
    }
    cout << ans << "\n";
    return 0;
}
