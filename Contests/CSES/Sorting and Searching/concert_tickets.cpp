#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m; cin >> n >> m;
    multiset<int> tickets;
    for(int i = 0, num; i < n; i++) cin >> num, tickets.insert(num);
    for(int num; m; m--){
        cin >> num;
        auto it = tickets.upper_bound(num);
        if(it != tickets.begin()){
            --it;
            cout << *it << "\n";
            tickets.erase(it);
        }else cout << "-1\n";
    }
    return 0;
}
