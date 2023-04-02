#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, c; cin >> n >> c;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 1, cost; i <= n; i++){
            cin >> cost;
            pq.push(i+cost); 
        }
        int ans = 0;
        while(!pq.empty() && c >= 0){
            c -= pq.top();
            pq.pop();
            ++ans; 
        }
        cout << ans-1+(c>=0) << "\n";
    }
    return 0;
}
