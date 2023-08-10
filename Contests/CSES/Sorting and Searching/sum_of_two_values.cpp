#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    map<int, int> mp;
    for(int i = 1, num; i <= n; i++){
        cin >> num;
        if(mp.count(x-num)){
            cout << mp[x-num] << " " << i << "\n";
            return 0;
        }
        mp[num] = i;
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
