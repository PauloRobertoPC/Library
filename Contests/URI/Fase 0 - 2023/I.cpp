#include <bits/stdc++.h>

using namespace std;

vector<int> adj[20];

int newMask(int mask, int key){
    for(int j:adj[key]) mask ^= (1<<(j-1));
    return mask;
}

void BFS(int mask){
    vector<int> dist(1<<11, -1); dist[mask] = 0;
    vector<tuple<int, int>> r(1<<11, {-1, -1}); r[mask] = {mask, -1};
    queue<int> q; q.emplace(mask);
    while(!q.empty()){
        mask = q.front(); q.pop();
        // cout << mask << "\n";
        for(int i = 1; i <= 10; i++){
            int mask2 = newMask(mask, i);
            if(dist[mask2] == -1){
                dist[mask2] = dist[mask]+1;
                r[mask2] = {mask, i};
                q.emplace(mask2);
            }
        }
    }
    if(dist[(1<<10)-1] == -1){
        cout << "-1\n";
        return;
    }
    vector<int> ans;
    int dad, key;
    tie(dad, key) = r[(1<<10)-1];
    while(key != -1){
        ans.emplace_back(key);
        tie(dad, key) = r[dad];
    }
    cout << ans.size() << "\n";
    reverse(ans.begin(), ans.end());
    for(int x:ans) cout << x << " "; cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    adj[1] = {2, 5};
    adj[2] = {1, 3, 5, 6};
    adj[3] = {2, 4, 6, 7};
    adj[4] = {3, 7};
    adj[5] = {1, 2, 6, 8};
    adj[6] = {2, 3, 5, 7, 8, 9};
    adj[7] = {3, 4, 6, 9};
    adj[8] = {5, 6, 9, 10};
    adj[9] = {6, 7, 8, 10};
    adj[10] = {8, 9};
    int mask = 0;
    for(int i = 0; i < 10; i++){
        int j; cin >> j;
        mask |= (j<<i);
    }
    BFS(mask);
    return 0;
}
