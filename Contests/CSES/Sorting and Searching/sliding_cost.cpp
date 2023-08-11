#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;

ll n, k;
map<ll, ll> compress;

struct BIT{
    ll maxn;
    vector<ll> bit;

    BIT(ll n) : maxn(n+10), bit(n+10, 0){}

    void update(ll pos, ll val){
        for(; pos < maxn; pos += (pos&(-pos))) bit[pos] += val;
    }

    ll get(ll pos){
        ll sum = 0;
        for(; pos > 0; pos -= (pos&(-pos))) sum += bit[pos];
        return sum;
    }

    ll get(ll l, ll r){
        return get(r) - get(l-1);
    }
};

ll calc(ordered_multiset<ll> &cj, BIT &count, BIT &sum){
    ll median = *cj.find_by_order((k-1)/2);
    ll cm = compress[median];

    ll cost_left = count.get(cm)*median - sum.get(cm);
    ll cost_right = sum.get(cm+1, n+2) - count.get(cm+1, n+2)*median;

    return cost_left+cost_right;
}

int main(){
    cin >> n >> k;
    vector<ll> v(n);
    for(ll &x:v) cin >> x, compress[x];

    ll c = 1;
    for(auto &[key, value]:compress) value = c++;

    BIT count(n), sum(n);

    ordered_multiset<ll> cj;
    for(ll i = 0; i < k; i++) cj.insert(v[i]), count.update(compress[v[i]], 1), sum.update(compress[v[i]], v[i]);
    cout << calc(cj, count, sum) << " ";;

    for(ll i = k; i < n; i++){
        cj.erase(cj.find_by_order(cj.order_of_key(v[i-k])));
        count.update(compress[v[i-k]], -1);
        sum.update(compress[v[i-k]], -v[i-k]);

        cj.insert(v[i]);
        count.update(compress[v[i]], 1);
        sum.update(compress[v[i]], v[i]);

        cout << calc(cj, count, sum) << " ";;
    }
    cout << "\n";

    return 0;
}
