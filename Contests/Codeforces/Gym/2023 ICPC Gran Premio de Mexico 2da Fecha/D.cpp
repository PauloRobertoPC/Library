#include <bits/stdc++.h>

using namespace std;

vector<int> Z(vector<int> &s){
    vector<int> z(s.size(), 0);
    for(int i = 1, l = 1, r = 1; i < s.size(); i++){
        if(i > r) l = r = i;
        z[i] = min(z[i-l], r-i);
        while(i+z[i] < s.size() && s[z[i]] == s[i+z[i]]){
            ++z[i];
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int &x:a) cin >> x;
    for(int &x:b) cin >> x;
    for(int i = 0; i < n-1; i++) a[i] -= a[i+1];
    for(int i = 0; i < m-1; i++) b[i] -= b[i+1];
    a.pop_back(); b.pop_back();
    int aux = a.size();
    a.push_back(int(1e9+7));
    for(auto x:b) a.push_back(x);
    auto z = Z(a);
    int ans = 0;
    for(int i = 0; i < z.size(); i++)
        ans += (z[i] == aux);
    cout << ans << "\n";
    return 0;
}
