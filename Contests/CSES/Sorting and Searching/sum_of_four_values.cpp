#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
int main(){
	ll n, x; cin >> n >> x;
	vector<ll> v(n);
	for(ll &z:v) cin >> z;
	set<pair<ll, pair<ll, ll>>> s;	
	s.insert({v[0]+v[1], {0, 1}});
	ll sum, comp;
	for(ll i = 2; i < n; i++){
		for(ll j = i+1; j < n; j++){
			sum = v[i]+v[j];
			comp = x-sum;
			auto it = s.lower_bound({comp, {-1, -1}});
			if(it != s.end() && (*it).first == comp){
				cout << (*it).second.first+1 << " " << (*it).second.second+1 << " " << i+1 << " " << j+1 << "\n"; 
				return 0;
			}
		}
		for(ll j = 0; j < i; j++){
			s.insert({v[j]+v[i], {j, i}});
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}
