#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n-1), w;
        for(int &x:v) cin >> x;
        bool bota = true;
        for(int i = 0; i < v.size()-1; i++){
            if(v[i] < v[i+1]){
                if(i+2 < v.size() && v[i+1] == v[i+2]){
                    w.emplace_back(v[i]);
                    w.emplace_back(0);
                    i++;
                }else if(bota){
                    w.emplace_back(v[i]);
                    w.emplace_back(0);
                    w.emplace_back(v[i+1]);
                    i++;
                    bota = false;
                }
            }else{
                w.emplace_back(v[i]);
            }
        }
        if(w.size()!=n)w.emplace_back(v.back());
        if(bota) w.emplace_back(0);
        for(int x:w) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
