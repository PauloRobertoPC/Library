#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, s, r; 
        cin >> n >> s >> r;
        deque<int> v(r/6, 6);
        if(r%6) v.emplace_back(r%6);
        int lack = n-v.size()-1;
        if(lack){
            while(lack){
                while(v.back() == 1) v.pop_back(), v.push_front(1);
                v.back()--;
                v.push_front(1);
                --lack;
            }
        }
        int aux = r - v.size();
        for(int i = 0; i < v.size(); i++) v[i] = 1 + aux/v.size();
        aux %= v.size();
        for(int i = 0; i < v.size(); i++) v[i] += min(1, aux), aux -= min(1, aux);
        v.push_back(s-r);
        sort(v.begin(), v.end());
        for(int x:v) cout << x << " "; cout << "\n";
    }
    return 0;
}
