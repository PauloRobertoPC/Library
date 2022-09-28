#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct BIT{
    ll maxn;
    vector<ll> bit;
    
    BIT(ll n) : bit(n+10, 0), maxn(n+10){}

    void update(ll pos, ll val){
        for(; pos < maxn; pos += (pos&(-pos))) bit[pos] += val;
    }

    ll sum(ll pos){
        ll ans = 0;
        for(; pos > 0; pos -= (pos&(-pos))) ans += bit[pos];
        return ans;
    }

    ll lower_bound(ll value){
		ll sum = 0;
		ll pos = 0;
		for (ll i = 20; i >= 0; i--){
			if ((pos + (1 << i) <= maxn-1) and (sum + bit[pos + (1 << i)] < value)){
				sum += bit[pos + (1 << i)];
				pos += (1 << i);
			}
		}
		return pos + 1;
	}
};

struct event{
    ll id, time, open;
    event(ll id, ll time) : id(id), time(time){}
    
    bool operator<(const event& b){
        return this->time < b.time;
    }
};

void add(ll id, vector<ll> &f, BIT &ff, BIT &sum){
    ff.update(f[id], -1);
    sum.update(f[id], -f[id]);
    f[id]++;
    ff.update(f[id], +1);
    sum.update(f[id], +f[id]);
}

void rem(ll id, vector<ll> &f, BIT &ff, BIT &sum){
    ff.update(f[id], -1);
    sum.update(f[id], -f[id]);
    f[id]--;
    ff.update(f[id], +1);
    sum.update(f[id], +f[id]);
}

ll get(BIT &ff, BIT &sum, ll k){
    ll pos = ff.lower_bound(k)-1; 
    ll qtd = k-ff.sum(pos);
    ll ans = sum.sum(pos)+(qtd*(pos+1))-k;
    // cout << pos << " " << qtd << " -> " << sum.sum(pos) << " + " << (qtd*(pos+1)) << " = " << ans << "\n";
    return ans;
}

//1 0
//2 2
//3 0


void solve(){
    ll n, k, x, d, m; cin >> n >> k >> x >> d >> m;
    vector<event> open, close;
    for(ll i = 0; i < m; i++){
        ll id, l, r; cin >> id >> l >> r; 
        open.push_back(event(id+1, l+1));
        close.push_back(event(id+1, r+1));
    }
    sort(open.begin(), open.end());
    sort(close.begin(), close.end());
    ll a = 0, b = 0, ans = 0, mmin = ll(1e18), mark = 1;
    vector<ll> f(max(n,m)+10, 1); BIT ff(max(n,m)+10), sum(max(n,m)+10); ff.update(1, n); sum.update(1, n); 
    for(ll i = x+1; i <= d+1; i++){
        // cout << "IIII: " << i-x << " " << i << "\n";
        // cout << "ABRINDO\n";
        while(a < m && open[a].time < i){
            // cout << open[a].time << " " << open[a].id << "\n";
            add(open[a++].id, f, ff, sum);
        }
        // cout << "FECHANDO\n";
        while(b < m && close[b].time <= i-x){
            // cout << close[b].time << " " << close[b].id << "\n";
            rem(close[b++].id, f, ff, sum);
        }
        // cout << "ANS\n";
        // cout << get(ff, sum, k) << "\n";
        mmin = min(mmin, get(ff, sum, k));
        // cout << "\n\n";
    }
    cout << mmin<< "\n";
}

int main(){
    ll t; cin >> t;
    for(ll i = 1; i <= t; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
