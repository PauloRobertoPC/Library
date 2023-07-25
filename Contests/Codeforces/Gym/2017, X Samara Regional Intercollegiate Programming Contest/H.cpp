#include <bits/stdc++.h>

using namespace std;

int n, m;
int M[1010][1010];

tuple<int, int, int> mmax(int ii, int jj){
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(i == ii) continue;
        for(int j = 0; j < m; j++){
            if(j == jj) continue;
            ans = max(ans, M[i][j]);
        }
    }
    return {ans, ii, jj};
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    priority_queue<tuple<int, int, int>> pq;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> M[i][j];
            pq.emplace(M[i][j], i, j);
        }
    }
    int x, y, a, b, c, d;
    tie(x, a, b) = pq.top(); pq.pop();
    tie(y, c, d) = pq.top();
    while(c == a || b == d){
        pq.pop();
        tie(y, c, d) = pq.top();
    }
    vector<tuple<int, int, int>> v;
    v.emplace_back(mmax(a, b));
    v.emplace_back(mmax(a, d));
    v.emplace_back(mmax(c, b));
    v.emplace_back(mmax(c, d));

    sort(v.begin(), v.end());
    tie(x, a, b) = v[0];
    cout << a+1 << " " << b+1 << "\n";

    return 0;
}
