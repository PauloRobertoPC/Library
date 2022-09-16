#include <bits/stdc++.h>

using namespace std;

int main(){
    int c, n; cin >> c >> n;
    vector<int> v(n);
    for(int &x:v) cin >> x;
    for(int i = 0; i < n; i++){
        int d = v[(i+2)%n] - v[i];
        if(d < 0) d += c;
        if(d <= c/n){
            cout << "N\n";
            return 0;
        }
    }
    cout << "S\n";
    return 0;
}
