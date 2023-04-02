#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    bool ok = true;
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        int a, c;
        cin >> a >> c;
        if(mp.count(c)){
            ok &= (mp[c] <= a); 
            mp[c] = max(mp[c], a);
        }else{
            mp[c] = a;
        }
    }
    cout << (ok ? "YES" : "NO") << "\n";
}
