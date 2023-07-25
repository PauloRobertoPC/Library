#include <bits/stdc++.h>

using namespace std;

#define maxm int(2e6+1)
#define maxn int(2e5+1)

int n;
set<int> cj;
int pos[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i = 1; i <= maxm; i++) cj.insert(i);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> pos[i];
        cj.erase(pos[i]);
    }
    int q; cin >> q;
    while(q--){
        int c; cin >> c;
        auto it = cj.upper_bound(pos[c]);
        int aux = *it;
        cj.erase(it);
        cj.insert(pos[c]);
        pos[c] = aux;
        cout << aux << "\n";
    }
    return 0;
}
