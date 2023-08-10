#include <bits/stdc++.h>
#include <cassert>

using namespace std;

#define mod ll(1e9+7)

typedef long long ll;

ll n;
vector<ll> f = {1, 1, 2};

ll binpow(ll b, ll e){
    ll ans = 1;
    while(e){
        if(e&1) ans = (ans*b)%mod;
        b = (b*b)%mod;
        e >>= 1;
    }
    return ans;
}

void show(vector<ll> &ans){
    vector<vector<char>> a(2, vector<char>());
    for(ll i = 0; i < ans.size(); i++){
        ll x = ans[i];
        while(x--){
            a[0].emplace_back('.');
            a[1].emplace_back('.');
        }
        if(i != ans.size()-1){
            a[0].emplace_back('#');
            a[1].emplace_back('#');
        }
    }
    for(auto c:a[0]) cout << c; cout << "\n";
    for(auto c:a[1]) cout << c; cout << "\n";
}

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> distr(2, 99);

unordered_map<ll, vector<ll>> val;

vector<ll> generate(ll &m){
    vector<ll> ans;
    ll tot = distr(gen);
    m = 1;
    while(tot >= 2){
        std::uniform_int_distribution<> distr(2, tot);
        ans.emplace_back(distr(gen));
        m = (m*f[ans.back()])%mod;
        tot -= ans.back()+1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(ll i = 3; i <= 200; i++)
        f.emplace_back((f[i-1]+f[i-2])%mod);
    cin >> n;
    if(n == 0){
        cout << "##.\n.##\n"; 
        return 0;
    }
    if(n == 1){
        cout << "#\n#\n"; 
        return 0;
    }
    for(ll i = 0; i < 1000000; i++){
        ll m = 1;
        vector<ll> mul = generate(m);
        val[m] = mul;
    }
    for(ll i = 0; i < 1000000; i++){
        ll m = 1;
        vector<ll> mul = generate(m);
        ll auxll = (n*binpow(m, mod-2))%mod;
        if(val.count(auxll)){
            vector<ll> aux = val[auxll];
            for(auto x:mul) aux.emplace_back(x);
            ll test = 1;
            for( auto x:aux) test = (test*f[x])%mod;
            show(aux);
            return 0;
        }
    }
    return 0;
}

