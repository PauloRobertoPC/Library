#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<int> f(m, 0);
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < m; j++)
            f[j] += (s[j] == 'o');
    }
    int ans = 0;
    for(int i = 0, j = 0; i < m; i = j){
        while(j < m && f[j] == n) ++j;
        ans = max(ans, j-i);
        j += (i == j);
    }
    cout << ans << "\n";
    return 0;
}
