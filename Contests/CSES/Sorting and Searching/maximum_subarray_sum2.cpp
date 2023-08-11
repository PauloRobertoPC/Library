#include <bits/stdc++.h>

using namespace std;

#define maxn ll(2e5+10)

typedef long long ll;

ll v[maxn], p[maxn];

struct min_queue{
    ll l = 1, r = 1;
    deque<array<ll, 2>> q;

    void push(ll val){
        while(!q.empty() && q.back()[0] >= val) q.pop_back();
        q.push_back({val, r++});
    }

    void pop(){
        if(!q.empty() && q.front()[1] == l++) q.pop_front();
    }

    ll get(){ return q.front()[0]; }

};

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    for(ll i = 1; i <= n; i++){
        cin >> v[i];
        p[i] = v[i]+p[i-1];
    }

    min_queue q; 
    ll ans = -1e18, pos_window = 0;

    //first window
    for(ll i = a; i <= b; i++, pos_window++){
        q.push(p[pos_window]);
        ans = max(ans, p[i]-q.get());
    }

    for(ll i = b+1; i <= n; i++, pos_window++){
        q.pop(); q.push(p[pos_window]);
        ans = max(ans, p[i]-q.get());
    }

    cout << ans << "\n";

    return 0;
}
