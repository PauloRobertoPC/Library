#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a = 0, b = 0;
        vector<int> ca, cb;
        for(int i = 1; i <= n-1; i++){
            if(i&1){
                a ^= i;
                ca.emplace_back(i);
            }else{
                b ^= i;
                cb.emplace_back(i);
            }
        }
        int c = a^b;
        bool trocou = false;
        if(n % 2 == 0){
            swap(ca, cb);
            swap(a, b);   
            trocou = true;
        }
        
        if(!c){ 
            ca.emplace_back(0);
        }else{
            ca.emplace_back((1<<20)^c);
            if(cb.back() == c) swap(cb[0], cb.back());
            int aux = cb.back();
            cb.pop_back();
            cb.emplace_back((1<<20)^aux);
        }
        
        if(trocou) swap(ca, cb);
        
        vector<int> v;
        for(int i = 0; i < n; i++){
            v.emplace_back(ca.back());
            ca.pop_back();
            swap(ca, cb);
        }
        for(int x:v) cout << x << " "; cout << "\n";
    }
    return 0;
}
