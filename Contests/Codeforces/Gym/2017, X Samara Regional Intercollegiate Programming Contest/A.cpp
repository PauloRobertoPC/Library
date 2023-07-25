#include <bits/stdc++.h>

using namespace std;

tuple<int, int, int> calc(string &s, int id){
    int mmin = 0, sum = 0;
    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        sum += (((ch=='(')*1) + ((ch==')')*(-1))); 
        mmin = min(mmin, sum);
    }
    return {abs(mmin), sum, id};
}

int main(){

    int n;
    cin >> n;
    vector<string> v(n);
    for(auto &s:v) cin >> s;
    vector<tuple<int, int, int>> op;
    for(int i = 0; i < n; i++) op.emplace_back(calc(v[i], i));

    vector<tuple<int, int, int>> pos, neg;
    for(auto [a, b, c]:op){
        if(b >= 0) pos.emplace_back(a, b, c);
        else{ 
            reverse(v[c].begin(), v[c].end());
            for(char &ch:v[c]) ch = (ch == '(' ? ')' : '(');
            neg.emplace_back(calc(v[c], c));
            for(char &ch:v[c]) ch = (ch == '(' ? ')' : '(');
            reverse(v[c].begin(), v[c].end());
        }
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    reverse(neg.begin(), neg.end());
    vector<int> ans;
    for(auto [a,b,c]:pos) ans.emplace_back(c);
    for(auto [a,b,c]:neg) ans.emplace_back(c);

    string s = "";
    for(int x:ans) s += v[x];
    int a, b, c; tie(a, b, c) = calc(s, 0);
    if(!a & !b){
        cout << "YES\n";
        for(int x:ans) cout << x+1 << " "; cout << "\n";
    }else{
        cout << "NO\n";
    }
    return 0;
}
