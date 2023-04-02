#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> tm(10001, 0);
    vector<pair<int, int>> v(n);
    for(auto &par:v) cin >> par.first >> par.second;
    sort(v.rbegin(), v.rend()); 
    for(int i = 0; i < n; i++){
        int d = v[i].second;
        while(d >= 1 && tm[d]) --d;
        if(d >= 1) tm[d] = v[i].first; 
    }
    int sum = 0;
    for(int x:tm) sum += x;
    cout << sum << "\n";
    return 0;
}
// Description: Greedy
