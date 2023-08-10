#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    if(n <= 4){
        cout << (n == 1 ? "1" : (n == 4 ? "2 4 1 3": "NO SOLUTION")) << "\n";
        return 0;
    }
    vector<int> p;
    for(int l = 1, r = n; l <= r; ++l, --r){
        p.emplace_back(r);
        if(l != r)
            p.emplace_back(l);
    }
    swap(p[0], p.back());
    for(int x:p) cout << x << " "; cout << "\n";
    return 0;
}
