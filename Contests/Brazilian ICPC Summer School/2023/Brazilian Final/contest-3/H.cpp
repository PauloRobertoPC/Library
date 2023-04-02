#include <bits/stdc++.h>

using namespace std;

int main(){
    int c, n;
    while(cin >> c >> n, c){ 
        map<int, vector<int>> mp;
        int acm = 0;
        for(int i = 0; i < n; i++){
            int num; cin >> num;
            acm = (acm+num)%c;
            mp[acm].emplace_back(i);
        }
        int l, r;
        if(mp.count(0)){
            l = 0, r = mp[0].back();
        }else{
            for(auto par:mp)
                if(par.second.size() >= 2)
                    l = par.second[0], r = par.second[1];
            ++l;
        }
        for(int i = l; i <= r; i++)
            cout << i+1 << " ";
        cout << "\n";
    }
    return 0;
}
// Desciption: Math - Pingeonhole Priciple + Modular Arithmetic + Prefix Sum
