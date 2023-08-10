#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(5));
    for(int i = 0; i < n; i++)
        for(int &x:v[i])
            cin >> x;
    int half = n/2;
    for(int i = 0; i < 5; i++){
        for(int j = i+1; j < 5; j++){
            int a = 0, b = 0, ab = 0;
            for(int k = 0; k < n; k++){
                if(v[k][i] && v[k][j]) ++ab;
                else if(v[k][i]) ++a;
                else if(v[k][j]) ++b;
            }
            if(a <= half && b <= half && ab == (2*half-a-b)){
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}
