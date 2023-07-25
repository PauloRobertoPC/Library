#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    if(v[0] == 5 && v[1] == 5 && v[2] == 7){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
    return 0;
}
