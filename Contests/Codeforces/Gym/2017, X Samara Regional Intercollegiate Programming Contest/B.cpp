#include <bits/stdc++.h>

using namespace std;

int main(){
    string t = "happiness";
    string s; cin >> s;
    int a, b, tot = 0;
    for(int i = 0; i < s.size(); i++){
        int j = 0;
        for(; j < t.size() && i+j < s.size() && t[j] == s[i+j]; j++);
        if(j == t.size()){
            if(!tot) a = b = i;
            if(tot) b = i;
            ++tot;
        }
    }
    if(tot > 2){
        cout << "NO\n";
    }else if(tot){
        cout << "YES\n";
        cout << a+1 << " " << b+3 << "\n";
    }else{
        cout << "YES\n";
        vector<int> mp(26, -1);
        for(int i = 0; i < s.size(); i++){
            int ich = s[i]-'a';
            if(mp[ich] != -1){
                cout << mp[ich]+1 << " " << i+1 << "\n";
                return 0;
            }
            mp[ich] = i;
        }
        cout << "1 2\n";
    }
    return 0;
}
