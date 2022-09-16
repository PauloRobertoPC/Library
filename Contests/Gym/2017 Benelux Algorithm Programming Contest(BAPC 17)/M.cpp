#include <bits/stdc++.h>

using namespace std;

int lis(vector<int> &a) {
	vector<int> dp;
	for (int i : a) {
		int pos = upper_bound(dp.begin(), dp.end(), i) - dp.begin();
		if (pos == dp.size()) dp.push_back(i);
		else dp[pos] = i;
	}
	return dp.size();
}

int main(){
    int n; cin >> n;
    int a, b, c, d; cin >> a >> b >> c >> d;
    vector<pair<int, int>> p;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y; 
        if(x >= min(a, c) && x <= max(a, c) && y >= min(b, d) && y <= max(b,d))
            p.emplace_back(x, y);
    }
    sort(p.begin(), p.end());
    if(a > c) swap(a, c), swap(b, d);
    if(b > d) reverse(p.begin(), p.end());
    vector<int> v;
    for(auto par:p) v.emplace_back(par.second);
    cout << lis(v) << "\n";
    return 0;
}
