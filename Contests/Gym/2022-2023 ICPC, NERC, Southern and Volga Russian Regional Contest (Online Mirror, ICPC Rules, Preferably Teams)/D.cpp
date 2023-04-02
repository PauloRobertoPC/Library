#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m;

bool ok(vector<ll> &v, int x){
    int l = x, r = n-1;
    while(l < r){
        if(v[l]+v[r] > m) return false;
        ++l;
        if(l < r){
            if(v[l]+v[r] > m) return false;
            --r;
        }
    }
    return true;
}

int bb(vector<ll> &v){
    int l = -1, r = n-1, mid;
    while(l < r-1){
        mid = (l+r)/2;
        if(ok(v, mid))
            r = mid;
        else
            l = mid;
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    ll sum = 0;
    vector<ll> v(n);
    for(ll &x:v) cin >> x, sum += x;
    sort(v.rbegin(), v.rend());

    cout << sum+bb(v)+1 << "\n";
    return 0;
}
