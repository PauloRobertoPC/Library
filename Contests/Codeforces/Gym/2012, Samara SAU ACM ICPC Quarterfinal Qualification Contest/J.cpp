#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, p;
    cin >> n >> p; --p;
    list<int> l;
    for(int i = 0, num; i < n; i++){
        cin >> num;
        l.emplace_back(num);
    }
    
    list<int>::iterator it = l.begin();
    for(int i = 0; it != l.end(); i++, it++){
        if(i == p) break;
    }
    
    int q; cin >> q;
    while(q--){
        string op; cin >> op;
        if(op[4] == 'R'){
            auto it2 = it; ++it2;
            if(it2 != l.end()) it = it2;
        }else if(op[4] == 'L'){
            if(it != l.begin()) --it;
        }else if(op[4] == 't'){
            cout << *it << "\n";
        }else{
            int num; cin >> num;
            if(op[6] == 'L'){
                l.insert(it, num);
            }else{
                auto it2 = it; it2++;
                l.insert(it2, num);
            }
        }
    }
    return 0;
}
