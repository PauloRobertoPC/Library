#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> pos(n+1);
    for(int i = 1, num; i <= n; i++){
        cin >> num;
        pos[num] = i;
    }
    int ans = 1, iam = pos[1];
    for(int i = 2; i <= n; i++){
        ans += (pos[i] < pos[i-1]);
        iam = pos[i];
    }
    cout << ans << "\n";
    return 0;
}
