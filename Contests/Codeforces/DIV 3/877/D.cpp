#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> v;

bool ok(ll mid){
    ll i = 0, op1 = v[0]+mid, op2, op3;
    for(; i < v.size() && abs(v[i]-op1) <= mid; i++);
    if(i == v.size()) return true;

    op2 = v[i]+mid;
    for(; i < v.size() && abs(v[i]-op2) <= mid; i++);
    if(i == v.size()) return true;

    op3 = v[i]+mid;
    for(; i < v.size() && abs(v[i]-op3) <= mid; i++);
    return i == v.size();
}

ll bb(){
    ll l = -1, r = v.back(), mid;
    while(l < r-1){
        mid = (l+r)/2;
        if(ok(mid)) r = mid;
        else l = mid;
    }
    return r;
}

int main(){
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        v.resize(n);
        for(ll &x:v) cin >> x;
        sort(v.begin(), v.end());
        cout << bb() << "\n";
    }
    return 0;
}
