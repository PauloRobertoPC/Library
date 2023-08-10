#include <bits/stdc++.h>

using namespace std;

int main(){
    string s; cin >> s;
    vector<int> f(26, 0);
    for(char ch:s) ++f[ch-'A'];
    int odd = 0;
    char codd;
    for(int i = 0; i < 26; i++){ 
        odd += ((f[i]&1) == 1);
        if(f[i]&1){
            --f[i];
            codd = i+'A';
        }
    }
    if(odd > 1){
        cout << "NO SOLUTION\n";
        return 0;
    }
    for(int i = 0; i < 26; i++){
        f[i] >>= 1;
        cout << string(f[i], i+'A');
    }
    if(odd == 1) cout << codd;
    for(int i = 25; i >= 0; i--) cout << string(f[i], i+'A');
    cout << "\n";
    return 0;
}
