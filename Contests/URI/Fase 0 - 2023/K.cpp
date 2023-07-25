#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
ll v[300];
unordered_map<ll, vector<ll>> mp;

void prec(){
    for(n = 0; n*n*n*n <= INT_MAX; n++) v[n] = n*n*n*n;
}

 
void calc(ll x){
    set<array<ll, 4>> cj;
	set<pair<ll, pair<ll, ll>>> s;
	s.insert({v[0]+v[1], {0, 1}});
	ll sum, comp;
	for(ll i = 2; i < n; i++){
		for(ll j = i+1; j < n; j++){
			sum = v[i]+v[j];
			comp = x-sum;
			auto it = s.lower_bound({comp, {-1, -1}});
			if(it != s.end() && (*it).first == comp)
                cj.insert({(*it).second.first, (*it).second.second, i, j});
		}
		for(ll j = 0; j < i; j++)
			s.insert({v[j]+v[i], {j, i}});
	}
    cout << cj.size() << "\n";
    for(auto v4:cj)
        cout << v4[0] << " " << v4[1] << " " << v4[2] << " " << v4[3] << "\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    prec();
    cout << n << "\n";
    ll q; cin >> q;
    while(q--){
        ll sla; cin >> sla;
        calc(sla);
    }
    return 0;
}
