#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int sum = 0;
    for(int i = 0, num; i < n-1; i++) cin >> num, sum = (sum+num)%n;
    int inf = 1e9;
    vector<int> ans(n, inf);
    for(int i = 0; i <= 20; i++)
        ans[(sum+i)%n] = min(ans[(sum+i)%n], i);
    for(int x:ans)
        cout << (x == inf ? -1 : x) << "\n";
    return 0;
}
