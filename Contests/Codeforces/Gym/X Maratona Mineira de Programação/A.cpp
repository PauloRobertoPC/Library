#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> v(4);
    for(int &x:v) cin >> x;
    for(int i = 0; i < 4; i++){
        bool ok = true;
        for(int j = 0; j < 4; j++){
            if(j == i) continue;
            ok &= (abs(j-i) == v[j]);
        }
        if(ok){
            cout << i+1 << "\n";
            return 0;
        }
    }
    return 0;
}
