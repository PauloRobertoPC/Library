#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    ordered_multiset<int> cj;
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int &x:v) cin >> x;

    for(int i = 0; i < k; i++) cj.insert(v[i]);
    cout << *cj.find_by_order((k-1)/2) << " ";

    for(int i = k; i < n; i++){
        cj.erase(cj.find_by_order(cj.order_of_key(v[i-k])));
        cj.insert(v[i]);
        cout << *cj.find_by_order((k-1)/2) << " ";
    }
    cout << "\n";

    return 0;
}
