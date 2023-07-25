#include <bits/stdc++.h>

using namespace std;

string s1, s2;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int c; cin >> c;
    while(c--){
        cin >> s1 >> s2; 
        map<int, int> lock;
        set<pair<int, int>> cj;
        for(int i = 0; i < s1.size(); i++)
            if(s1[i] == s2[i])
                cj.emplace(i, i);
        int t, q;
        cin >> t >> q;
        int curr = 0, tot_block = 0;
        while(q--){
            int op; cin >> op;
            if(lock.count(curr)){
                --tot_block;
                int pos = lock[curr];
                if(s1[pos] == s2[pos]) cj.emplace(pos, pos);
                lock.erase(curr);
            }
            if(op == 1){
                int pos;
                cin >> pos; --pos;
                lock[curr+t] = pos;
                cj.erase({pos, pos});
                ++tot_block;
            }else if(op == 2){
                int op1, pos1, op2, pos2; 
                cin >> op1 >> pos1 >> op2 >> pos2;
                --pos1; --pos2;
                if(s1[pos1] == s2[pos1]) cj.erase({pos1, pos1});
                if(s1[pos2] == s2[pos2]) cj.erase({pos2, pos2});
                if(op1 == op2){
                    if(op1 == 1) swap(s1[pos1], s1[pos2]);
                    else swap(s2[pos1], s2[pos2]);
                }else{
                    if(op1 == 1) swap(s1[pos1], s2[pos2]);
                    else swap(s2[pos1], s1[pos2]);
                }
                if(s1[pos1] == s2[pos1]) cj.insert({pos1, pos1});
                if(s1[pos2] == s2[pos2]) cj.insert({pos2, pos2});
            }else{
                cout << ((cj.size() == s1.size()-tot_block) ? "YES" : "NO") << "\n";
            }
            ++curr;
        }
    }
    return 0;
}
