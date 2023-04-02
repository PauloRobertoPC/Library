#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n+1);
        for(int i = 1; i <= n; i++) cin >> v[i];
        int t1 = 0, t2 = 0;
        vector<bool> c1(n+1, false), c2(n+1, false);
        for(int i = 1; i <= n; i++){
            if(v[i] != i) c1[i] = true, ++t1;
            if(v[i] != n-i+1) c2[i] = true, ++t2;
        }
        int t3 = 0, t4 = 0;
        for(int i = 1; i <= n; i++){
            if(c1[i] && !c2[i]) ++t3;
            else if(!c1[i] && c2[i]) ++t4;
        }
        int ans = -1;
        for(int i = 1; i <= n; i++){
            if(t3)
                --t1, --t3;
            else if(t1)
                --t1, --t2, --t3;
            t1 = max(t1, 0); t2 = max(t2, 0); t3 = max(t3, 0);
            if(t1 == t2 && t2 == 1 && t1+t3 == 1 && t2+t4 == 1)
                break;
            if(t1 == 0){
                ans = i%2;
                break;
            }
            swap(t1, t2);
            swap(t3, t4);
        }
        cout << (ans == -1 ? "Tie" : (ans == 1 ? "First" : "Second")) << "\n";
    }
    return 0;
}
