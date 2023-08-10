#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, ans = 0;
    map<int, int> pos;
    cin >> n;
    for(int l = 0, r = 0, num; r < n; r++){
        cin >> num;
        l = max((pos.count(num) ? pos[num]+1 : l), l);
        pos[num] = r;
        ans = max(ans, r-l+1);
    }
    cout << ans << "\n";
    return 0;
}
