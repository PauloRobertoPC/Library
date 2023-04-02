#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;
        string s = "";
        if(n0) s += '0';
        while(n0--) s += '0';
        if(n2){
            if(s.size()) --n1;
            s += '1';
        }
        while(n2--) s += '1';
        char c1 = '0', c2 = '1';
        if(s.size() == 0) s += '1';
        if(s.back() == '0') swap(c1, c2);
        while(n1--) s += c1, swap(c1, c2);
        cout << s << "\n";
    }
    return 0;
}
