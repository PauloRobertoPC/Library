#include <bits/stdc++.h>

using namespace std;

#define mod ll(1e9+7)

typedef long long ll;

vector<ll> f = {1, 1, 2};
map<ll, ll> dp, dad;

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

ll n;
bool solve(int i, ll acm, ll sum){
    // cout << i << " " << acm <<"\n";
    if(acm==n)
        return true;
    if(sum > 200) return false;
    if(i==f.size())
        return acm==n;
    if(acm==n)
        return true;
    return solve(i,(acm*f[i])%mod, sum+i+1)  || solve(i+1,acm, sum+i+1);
}

int main(){
    for(ll i = 3; i <= 200; i++){
        f.emplace_back((f[i-1]+f[i-2])%mod);
    }
    vector<ll> ans;
    cin >> n;
    cout << solve(2,1, -1) <<"\n";
    return 0;
}

