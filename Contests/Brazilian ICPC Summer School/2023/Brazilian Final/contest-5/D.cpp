#include <bits/stdc++.h>

using namespace std;

vector<int> z_function(string s) {
  int n = (int) s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; i++){
    if (i <= r)
      z[i] = min (r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]])
      z[i]++;
    if (i + z[i] - 1 > r)
      l = i, r = i + z[i] - 1;
  }
  return z;
}

int main(){
    string s, t, trash; 
    getline(cin, s);
    getline(cin, t);
    int oc; cin >> oc;
    vector<int> cnt = z_function(t+'$'+s); 
    vector<int> f(t.size()+1, 0);
    for(int i = t.size(); i < cnt.size(); i++) ++f[cnt[i]];
    int acm = 0;
    int i = t.size();
    for(; i > 0 && acm < oc; i--) acm += f[i]; 
    cout << (acm >= oc ? t.substr(0, i+1) : "IMPOSSIBLE") << "\n"; 
    return 0;
}
// Description: String - Z Function
