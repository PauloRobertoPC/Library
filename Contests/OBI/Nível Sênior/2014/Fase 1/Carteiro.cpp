#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    map<int, int> pos;
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        pos[c] = i+1;
    }
    int ans = 0, pos_atual = 1;
    for(int i = 0; i < m; i++){
        int c;
        cin >> c;
        ans += abs(pos_atual-pos[c]);
        pos_atual = pos[c];
    }
    cout << ans << "\n";
    return 0;
}
