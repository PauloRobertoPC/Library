#include <bits/stdc++.h>

using namespace std;

#define container unordered_set<string>

container can, can2;

container inc_mask(string &s, int mask){
    vector<pair<int, int>> interval;
    for(int i = 0, j; i < s.size(); i++){
        if((mask&(1<<i)) == 0) continue;
        j = i;
        while(j < s.size() && (mask&(1<<j)) != 0) j++;
        interval.emplace_back(i, j);
        i = j-1;
    }
    container cj;
    for(auto [l, r]:interval){
        for(int i = l; i < r; i++){
            for(int j = i; j < r; j++){
                string part = s.substr(i, j-i+1);
                cj.insert(part);
                reverse(part.begin(), part.end());
                cj.insert(part);
            }
        }
    }
    return cj;
}

int bigger(int pos, int mask, string &t){
    for(int j = pos; j < t.size() && (can.count(t.substr(pos, j-pos+1)) || can2.count(t.substr(pos, j-pos+1))); j++)
        mask |= (1<<j);
    return mask;
}

int bfs(string &t){
    vector<int> dist(1<<t.size(), -1);
    queue<int> q; q.emplace(0);
    dist[0] = 0;
    while(!q.empty()){
        int mask = q.front(); q.pop();
        // cout << mask << " " << dist[mask] << "\n";
        if(mask == (1<<(t.size()))-1) return dist[mask];
        can2 = inc_mask(t, mask);
        for(int i = 0; i < t.size(); i++){
            if((mask&(1<<i)) != 0) continue;
            int mask2 = bigger(i, mask, t);
            if(dist[mask2] == -1){
                dist[mask2] = dist[mask] + 1;
                q.push(mask2);
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        string s, t, r="";
        cin >> s >> t;
        can = inc_mask(s, (1<<(s.size()))-1);
        int ans = bfs(t);
        if(ans != -1) cout << ans << "\n";
        else cout << "impossible\n";
    }
    return 0;
}
