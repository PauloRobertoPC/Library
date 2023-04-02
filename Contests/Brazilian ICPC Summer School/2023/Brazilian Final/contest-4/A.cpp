#include <bits/stdc++.h>

using namespace std;

int n, num;
set<int> in_game;

void ask(int bit){
    vector<vector<int>> ids(2, vector<int>());
    for(int i:in_game){
        cout << "? " << i << " " << bit << endl;
        int ans; cin >> ans;
        ids[ans].emplace_back(i);
    }
    
    int um = 0, tot = 0;
    for(int i = 0; i <= n; i++){
        bool ok = true;
        for(int j = 0; j < bit; j++){
            if((i&(1<<j)) != (num&(1<<j))) ok = false;
        }
        if(!ok) continue;
        ++tot;
        um += ((i&(1<<bit)) != 0);
    }
    int zero = tot-um;
    
    int bit_correct = (ids[0].size() < zero ? 0 : 1);
    for(int id:ids[bit_correct^1]) in_game.erase(id);
    num |= (bit_correct<<bit);
}

int main(){
    cin >> n;
    int lg = 32-__builtin_clz(n);
    for(int i = 1; i <= n; i++) in_game.insert(i);
    for(int i = 0; i < lg; i++)
        ask(i);    
    cout << "! " << num << endl;
    return 0;
}
// Description: Math - Bits + Observation + Iteractive Problem
