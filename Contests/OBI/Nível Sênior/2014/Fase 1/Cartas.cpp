#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> v(5);
    for(auto &x:v) cin >> x;
    int mmax = -1000, mmin = 1000;
    for(int i = 1; i < 5; i++){
        mmax = max(mmax, v[i]-v[i-1]);
        mmin = min(mmin, v[i]-v[i-1]);
        // 13 10 9 5 3 2
    }
    if(mmax < 0 && mmin < 0){
        cout << "D\n";
    }else if(mmax > 0 && mmin > 0){
        cout << "C\n";
    }else{
        cout << "N\n";
    }
    return 0;
}
