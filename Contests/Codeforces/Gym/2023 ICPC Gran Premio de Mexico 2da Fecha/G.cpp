#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n, t;
    cin >> n >> t;
    ll mi = 0, mo = 0;
    vector<ll> in(n+1, 0);
    vector<ll> out(n+1, 0);
    ll mmax = 0;
    priority_queue<ll> pq; pq.emplace(0);
    ll tot = 0;
    while(t--){
        ll u, v; cin >> u >> v;
        tot += in[u] + out[v] + (u == v);
        ++out[u]; ++in[v];
        mi = max(mi, in[v]);
        mo = max(mo, out[u]);
        mmax = max(mmax, in[u]+out[u]);
        mmax = max(mmax, in[v]+out[v]);
        pq.emplace(max(mi+mo, mmax+1));
        cout << tot << " " << pq.top() << "\n";
    }
    return 0;
}
