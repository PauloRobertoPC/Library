#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    vector<int> v;
    for(char ch:s){
        if(ch == 'I') v.emplace_back(1); 
        else if(ch == 'V') v.emplace_back(5);
        else if(ch == 'X') v.emplace_back(10);
        else if(ch == 'L') v.emplace_back(50);
        else if(ch == 'C') v.emplace_back(100);
        else if(ch == 'D') v.emplace_back(500);
        else if(ch == 'M') v.emplace_back(1000);
    }
    stack<pair<int, int>> st;
    vector<int> proximo_maior(v.size(), -1);
    for(int i = 0; i < v.size(); i++){
        while(!st.empty() && st.top().first < v[i]){
            proximo_maior[st.top().second] = i; 
            st.pop();
        }
        st.push({v[i], i});
    }
    for(int i = 0; i < v.size(); i++)
        if(proximo_maior[i] != -1)
            v[proximo_maior[i]] -= v[i], v[i] = 0;
    int ans = 0;
    for(int i = 0; i < v.size(); i++)
        ans += v[i];
    cout << ans << "\n";
    return 0;
}
