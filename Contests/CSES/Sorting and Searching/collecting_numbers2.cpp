#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, ans = 1;
    cin >> n >> m;
    vector<int> v(n+1), pos(n+1, -1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        pos[v[i]] = i;
    }

    for(int i = 1; i < n; i++)
        ans += (pos[i] > pos[i+1]);

    for(int a, b; m; m--){
        cin >> a >> b;

        if(v[a] > v[b]) swap(a, b);
        ans -= (v[a] != n && pos[v[a]] > pos[v[a]+1]);
        ans -= (v[b] != n && pos[v[b]] > pos[v[b]+1]);
        ans -= (v[a] != 1 && pos[v[a]-1] > pos[v[a]]);
        if(v[a]+1 != v[b])
            ans -= (v[b] != 1 && pos[v[b]-1] > pos[v[b]]);

        swap(v[a], v[b]);
        pos[v[a]] = a;
        pos[v[b]] = b;

        if(v[a] > v[b]) swap(a, b);
        ans += (v[a] != n && pos[v[a]] > pos[v[a]+1]);
        ans += (v[b] != n && pos[v[b]] > pos[v[b]+1]);
        ans += (v[a] != 1 && pos[v[a]-1] > pos[v[a]]);
        if(v[a]+1 != v[b])
            ans += (v[b] != 1 && pos[v[b]-1] > pos[v[b]]);

        cout << ans << "\n";
    }
    return 0;
}
