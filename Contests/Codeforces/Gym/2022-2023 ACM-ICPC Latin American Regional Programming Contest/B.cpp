#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

ll n, m;
vector<ll> ans;
vector<pair<ll, ll>> p, r;

void bb(){
    ans.assign(n, m);
    vector<ll> L(n, 0), R(n, m-1);
    for(ll it = 0; it < 27; it++){
        vector<vector<ll>> q(m, vector<ll>());
        for(ll i = 0; i < n; i++){
            ll mid = (L[i]+R[i])/2;
            q[mid].emplace_back(i);
        }
        LineContainer lc;
        for(ll mid = 0; mid < m; mid++){
            lc.add(r[mid].first, r[mid].second);
            for(ll id:q[mid]){
                ll firstY = lc.query(p[id].first);
                ll y = p[id].second;
                if(y < firstY){
                    ans[id] = min(ans[id], mid); 
                    R[id] = max(L[id], mid-1);
                }else{
                    L[id] = min(mid+1, R[id]); 
                }
            }
        }
    }
}

int main(){
    cin >> n;
    p.resize(n);
    for(auto &[x, y]:p)
        cin >> x >> y;
    cin >> m;
    r.resize(m);
    for(auto &[a, b]:r)
        cin >> a >> b;
    bb();
    vector<vector<ll>> ans_line(m+1, vector<ll>());
    for(ll i = 0; i < n; i++)
        ans_line[ans[i]].emplace_back(i);
    for(ll i = 0; i < m; i++){
        cout << ans_line[i].size() << " ";
        for(ll x:ans_line[i]) cout << x+1 << " ";
        cout << "\n";
    }
    return 0;
}
