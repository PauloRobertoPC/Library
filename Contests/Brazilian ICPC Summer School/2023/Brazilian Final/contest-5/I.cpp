#include <bits/stdc++.h>

using namespace std;

#define mod ll(1e9+7)

typedef long long ll;

struct Matrix{
    vector<vector<ll>> M; 

    Matrix(ll n){
        M.assign(n, vector<ll>(n, 0));
    }

    Matrix operator*(Matrix o){
        ll n = M.size();
        Matrix ans(n);
        for(ll i = 0; i < n; i++)
            for(ll j = 0; j < n; j++)
                for(ll k = 0; k < n; k++)
                   ans.M[i][j] = (ans.M[i][j] + (this->M[i][k]*o.M[k][j])%mod)%mod;
        return ans;
    }

    Matrix operator^(ll e){
        ll n = M.size();
        Matrix ans(n), b(n);
        b.M = this->M;
        for(ll i = 0; i < n; i++) ans.M[i][i] = 1;
        while(e){
            if(e&1) ans = ans*b;
            e >>= 1;
            b = b*b;
        }
        return ans;
    }
};

int main(){
    ll n; cin >> n;  
    Matrix M(5);
    M.M = {
        {16, 9, 4, 1, 0},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0}
    };
    ll e = n/10, lim = 5-(n%10 >= 5), ans = 0;
    Matrix M2 = M^(e);
    for(ll i = 0; i < lim; i++)
        ans = (ans+M2.M[i][0])%mod;
    cout << ans << "\n";
    return 0;
}
// Description: Math - Linear Recurrence
