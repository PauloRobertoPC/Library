#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(int &x:v) cin >> x;
    int i = n-1, j = n-1;
    vector<pair<int, int>> ans;
    while(i >= 0){
        if(!v[i]){
            --i;
        }else if(i < j){
            --v[i];
            ans.emplace_back(i+1, j+1);
            --j;
        }else{
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for(auto [x, y]:ans)
        cout << x << " " << y << "\n";
    return 0;
}
