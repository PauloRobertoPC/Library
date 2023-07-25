#include <bits/stdc++.h>

using namespace std;

int main(){
    string s; cin >> s;
    for(auto &ch:s) ch += 32;
    vector<int> o;
    for(int i = 0; i < s.size(); i++)
        if(s[i] == 's')
            o.emplace_back(i);
    cout << s << "\n";
    for(int i = 1; i < o.size(); i++){
        if(o[i-1]+1 == o[i]){
            cout << s.substr(0, o[i-1]) + "B" + s.substr(o[i]+1, s.size()) << "\n";
        }
    }
    return 0;
}
