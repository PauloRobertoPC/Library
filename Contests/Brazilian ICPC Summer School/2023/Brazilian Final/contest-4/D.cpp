#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> dg(n+1);
    for(int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        ++dg[u];
        ++dg[v];
    }
    int leafs = 0;
    for(int i = 1; i <= n; i++) leafs += (dg[i] == 1);
    cout << ((leafs+1)/2) << "\n";
    return 0;
}
// Description: Graph - Answer in function of quantity of leafs in the Tree
