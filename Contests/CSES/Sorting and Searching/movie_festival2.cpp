#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k, ans = 0; cin >> n >> k;
    vector<array<int, 2>> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i][1] >> v[i][0];
    sort(v.begin(), v.end());

    multiset<int> end;
    for(int i = 0; i < k; i++) end.insert(0);

    for(int i = 0; i < n; i++){
        auto it = end.upper_bound(v[i][1]);
        if(it == end.begin()) continue;

        --it;
        end.erase(it);

        end.insert(v[i][0]);

        ++ans;
    }
    cout << ans << "\n";
    return 0;
}
