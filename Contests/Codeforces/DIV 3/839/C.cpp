#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int k, n; cin >> k >> n;
        vector<int> v(k);
        for(int i = k-1, c = 0; i >= 0; i--, c++) v[i] = n-c;
        int tot = v[0]-1;
        for(int i = k-2, a = 1; i >= 0; i--, a++){
            if(tot-a < 0) continue;
            for(int j = i; j >= 0; j--) v[j] -= a;
            tot -= a; 
        }
        for(int x:v) cout << x << " "; cout << "\n";
    }
    return 0;
}
