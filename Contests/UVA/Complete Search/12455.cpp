#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int s, n; cin >> s >> n;
        vector<int> v(n);
        for(int &x:v) cin >> x;
        bool ok = false;
        for(int i = 0; i < (1<<n); i++){
            int sum = 0;
            for(int j = 0; j < n; j++)
                if(i&(1<<j))
                    sum += v[j];
        
            ok |= (sum == s);
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
