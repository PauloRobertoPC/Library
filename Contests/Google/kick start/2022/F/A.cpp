#include <bits/stdc++.h>

using namespace std;

struct st{
    string color; int d, u;

    st(){}
    st(string color, int d, int u) : color(color), d(d), u(u){}
};

bool cmp1(st a, st b){
    if(a.color != b.color) return a.color < b.color;
    return a.u < b.u;
}

bool cmp2(st a, st b){
    if(a.d != b.d) return a.d < b.d;
    return a.u < b.u;
}


void solve(){
    int n; cin >> n;
    vector<st> v, v1, v2;
    for(int i = 0; i < n; i++){
        string c; int d, u; cin >> c >> d >> u;
        v.push_back(st(c, d, u));
    }
    v1 = v; v2 = v;
    sort(v1.begin(), v1.end(), cmp1);
    sort(v2.begin(), v2.end(), cmp2);
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += (v1[i].u == v2[i].u);
    }
    cout << ans << "\n";
}

int main(){
    int t; cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
