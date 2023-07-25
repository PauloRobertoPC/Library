#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<string> v(n);
    vector<pair<int, int>> p(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        p[i] = {0, i};
    }
    int m;
    cin >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        --a; --b;
        p[a].first = p[b].first + 1;
        p[a].second = p[b].second;
    }
    for(int i = 0; i < p[0].first; i++)
        cout << "I_love_";
    cout << v[p[0].second] << "\n";
    return 0;
}
