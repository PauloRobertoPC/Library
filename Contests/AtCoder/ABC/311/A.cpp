#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    set<char> cj; 
    cj.insert('A');
    cj.insert('B');
    cj.insert('C');
    for(int i = 0; i < n; i++){
        cj.erase(s[i]);
        if(cj.empty()){
            cout << i+1 << "\n";
            return 0;
        }
    }
    return 0;
}
