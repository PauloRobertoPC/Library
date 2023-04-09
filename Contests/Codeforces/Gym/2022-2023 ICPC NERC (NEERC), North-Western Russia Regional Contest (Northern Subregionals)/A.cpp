#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> v(4);
    int mmin = 1234;
    for(int &x:v) cin >> x, mmin = min(mmin, x);
    int pad; cin >> pad;
    bool ok = true;
    for(int i = 1; i < 4; i++)
        ok &= (v[i-1] == v[i]);   
    if(ok){
        cout << "1\n";
        return 0;
    }
    for(int &x:v) if(x == mmin){
        x += pad;
        break;
    }
    ok = true;
    for(int i = 1; i < 4; i++)
        ok &= (v[i-1] == v[i]);   
    cout << (ok ? "1" : "0") << "\n";
    return 0;
}
