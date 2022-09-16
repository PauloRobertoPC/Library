#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<char, int> a, pair<char, int> b){
    if(a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = s.size();
        vector<pair<char, int>> v;
        for(int i = 0; i < n; i++)
            if(s[i] >= min(s[0], s.back()) && s[i] <= max(s[0], s.back()))
                v.emplace_back(s[i], i);
        sort(v.begin(), v.end());
        if(s[0] > s.back()) sort(v.begin(), v.end(), cmp);
        else sort(v.begin(), v.end());
        int sum = 0;
        for(int i = 1; i < v.size(); i++) sum += abs(v[i].first-v[i-1].first);
        cout << sum << " " << v.size() << "\n";
        for(auto &par:v) cout << par.second+1 << " ";
        cout << "\n";
    }
    return 0;
}
