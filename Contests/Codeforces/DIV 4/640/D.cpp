#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        for(int &x:v) cin >> x;
        int l = 0, r = n-1, sa = 0, sb = 0, mv = 0, op = 0, ata = 0, atb = 0;
        while(l <= r){
            int tot = 0;
            if(!op){
                while(l <= r && tot <= atb) tot += v[l++];
                sa += tot;
                ata = tot;
            }else{
                while(l <= r && tot <= ata) tot += v[r--];
                sb += tot;
                atb = tot;
            }
            op ^= 1;
            ++mv;
        }
        cout << mv << " " << sa << " " << sb << "\n";
    }
    return 0;
}
