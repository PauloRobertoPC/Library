#include <bits/stdc++.h>

using namespace std;

vector<int> pi(string s){
    vector<int> p(s.size(), 0);
    for(int i = 1, j = 0; i < s.size(); i++){
        while(j > 0 && s[i] != s[j]) j = p[j-1];
        if(s[i] == s[j]) ++j;
        p[i] = j;
    }
    return p;
}

int main(){
    string s; cin >> s; int n = s.size();
    auto p = pi(s);
    for(int i = 0; i < n; i++) cout << i << " -> " << p[i] << "\n";
    int a = 0, b, c, d = n-1;
    for(int i = 1; i <= n; i++){
        int b = i*((n)/i) - 1;
        int c = b+1;
        int k = ((b-a+1)-p[b]);
        cout << i << " -> " << k << " " << a << " " << b << " " << c << " " << d << "\n";
        if((b-a+1)%k == 0 && p[n-1] >= (d-c+1))
            cout << i << "\n";
    }
    return 0;
}
