#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    set<char> cj;
    for(int i = 0; i < n; i++){
        char ch;
        cin >> ch;
        cj.insert(ch);
    }
    while(true){
        string s = to_string(n);
        bool ok = true;
        for(auto ch:s){
            ok &= !cj.count(ch);
        }
        if(ok) break;
        ++n;
    }
    cout << n << "\n";
    return 0;
}
