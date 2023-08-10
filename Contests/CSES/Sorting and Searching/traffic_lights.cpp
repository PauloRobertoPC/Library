#include <bits/stdc++.h>

using namespace std;

int main(){
    int x, q;
    cin >> x >> q;

    set<pair<int, int>> cj; cj.emplace(x, 0);
    priority_queue<tuple<int, int, int>> pq; pq.emplace(x, x, 0);

    for(int rm, mmax, l, r; q; q--){
        cin >> rm;

        auto it = cj.upper_bound({rm, -1});
        r = it->first; l = it->second;
        cj.erase(it);

        cj.emplace(rm, l);
        pq.emplace(rm-l, rm, l);

        cj.emplace(r, rm);
        pq.emplace(r-rm, r, rm);

        tie(mmax, r, l) = pq.top();
        while(!cj.count({r, l})){
            cj.erase({r, l});
            pq.pop();
            tie(mmax, r, l) = pq.top();
        }

        cout << mmax << " ";
    }
    cout << "\n";
    return 0;
}
