#include <bits/stdc++.h>

using namespace std;

int main(){
    string pi = "314159265358979323846264338327950288419716939937510";
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int i = 0;
        for(;i < s.size() && s[i] == pi[i]; i++);
        cout << i << "\n";
    }
    return 0;
}
