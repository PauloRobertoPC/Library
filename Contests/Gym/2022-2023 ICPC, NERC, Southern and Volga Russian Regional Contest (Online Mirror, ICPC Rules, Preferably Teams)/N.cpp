#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define maxn int(5e5+10)

int k;
string s; 
vector<int> f[10];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        cin >> s >> k;
        string t = "";
        int n = s.size();
        for(int i = 0; i < n; i++) f[s[i]-'0'].emplace_back(i);
        for(int i = 0; i < n; i++){
            if(n-i == k) break; 
            for(int j = (i==0); j <= (s[i]-'0'); j++){
                auto it = lower_bound(f[j].begin(), f[j].end(), i);
                if(it == f[j].end()) continue;
                int pos = *it;
                int d = pos-i;
                if(d <= k){
                    k -= d; 
                    t += char('0'+j);
                    i = pos;
                    break;
                }
            }
        }
        cout << t << "\n";
        for(int i = 0; i < 10; i++) f[i].clear();
    }
    return 0;
}
