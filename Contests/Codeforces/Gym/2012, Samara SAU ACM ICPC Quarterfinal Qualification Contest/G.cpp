#include <bits/stdc++.h>

using namespace std;

int main(){
    set<char> cj;
    for(char ch = 'a'; ch <= 'z'; ch++) cj.insert(ch);
    string s;
    cin >> s;
    vector<bool> used(s.size(), 0);
    int c = 0;
    for(auto ch:s){
        if(cj.count(ch)){
            cj.erase(ch);
            used[c] = 1;
        }
        ++c;
    }
    for(int i = 0; i < s.size(); i++){
        if(!used[i]){
            if(cj.empty()){
                cout << "IMPOSSIBLE\n";
                return 0;
            }
            s[i] = *cj.begin();
            cj.erase(cj.begin());
        }
    }
    cout << s << "\n";
    return 0;
}
