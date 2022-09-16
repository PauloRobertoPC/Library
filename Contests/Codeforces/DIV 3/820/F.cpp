#include <bits/stdc++.h>

using namespace std;

#define INF int(1e9)

int query(vector<int> &p, int l, int r){
    if(l == 0) return p[r]%9;
    return (p[r]-p[l-1])%9;
}

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = s.size();
        int w, m; cin >> w >> m;
        vector<int> p(n);
        for(int i = 0; i < n; i++){
            p[i] = (s[i]-'0');
            if(i > 0) p[i] += p[i-1];
        }
        vector<vector<int>> r(10);
        r[(p[w-1])%9].emplace_back(0);
        for(int i = w; i < n; i++) r[(p[i]-p[i-w])%9].emplace_back(i-w+1);
        int a, b, c;
        while(m--){
            cin >> a >> b >> c;
            int x = INF, y = INF;
            for(int i = 0; i < 9; i++){
                if(r[i].size() == 0) continue;
                for(int j = 0; j < 9; j++){
                    if((i*query(p, a-1, b-1) + j)%9 == c){
                        if(i == j && r[i].size() == 1 || r[j].size() == 0) continue;
                        int auxx = r[i][0];
                        int auxy = (i == j ? r[j][1] : r[j][0]);
                        if(auxx == x && auxy < y) y = auxy;
                        else if(auxx < x) x = auxx, y = auxy;
                    }
                }
            }
            cout << (x == INF ? -1 : x+1) << " ";
            cout << (y == INF ? -1 : y+1) << "\n";
        }
    }
    return 0;
}
