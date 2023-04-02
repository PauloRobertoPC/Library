#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll X, Y, a, b, c;
    cin >> X >> Y >> a >> b >> c;
    vector<ll> r(a), g(b), cl(c);
    for(ll &x:r) cin >> x;
    for(ll &x:g) cin >> x;
    for(ll &x:cl) cin >> x;
    sort(r.rbegin(), r.rend());
    sort(g.rbegin(), g.rend());
    sort(cl.rbegin(), cl.rend());
    ll sum = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(ll i = 0; i < X; i++){
        sum += r[i];    
        pq.push(r[i]);
    }
    for(ll i = 0; i < Y; i++){
        sum += g[i];    
        pq.push(g[i]);
    }
    for(ll i = 0; i < c; i++){
        if(pq.empty()) continue;
        while(!pq.empty() && pq.top() > cl[i]) pq.pop();
        if(!pq.empty()) sum = sum - pq.top() + cl[i], pq.pop();
    }
    cout << sum << "\n";
    return 0;
}
// Description: Greedy(easy)
