#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).

int main(){
    int n, k;
    cin >> n >> k;

    ordered_set<int> cj;
    for(int i = 1; i <= n; i++) cj.insert(i);

    int pos = 0;
    for(int i = 1; i <= n; i++){
        pos = (pos+k)%cj.size();
        auto it = cj.find_by_order(pos);
        cout << *it << " ";
        cj.erase(it);
    }
    cout << "\n";

    return 0;
}
