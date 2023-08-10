#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    multiset<int> cj;
    vector<int> v(n);
    for(int &x:v) cin >> x;

    for(int i = 0; i < n; i++){
        auto it = cj.upper_bound(v[i]);
        if(it != cj.end())
            cj.erase(it);
        cj.insert(v[i]);
    }

    cout << cj.size() << "\n";
    return 0;
}
