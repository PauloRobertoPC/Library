#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    vector<int> p(n), a(m);
    for(int &x:p) cin >> x;
    for(int &x:a) cin >> x;
    sort(p.begin(), p.end());
    sort(a.begin(), a.end());
    for(int i = 0, j = 0; i < m && j < n; j++){
        while(i < m && a[i] < p[j]-k) ++i;
        if(i < m && abs(a[i]-p[j]) <= k) ++i, ++ans;
    }
    cout << ans << "\n";
    return 0;
}
