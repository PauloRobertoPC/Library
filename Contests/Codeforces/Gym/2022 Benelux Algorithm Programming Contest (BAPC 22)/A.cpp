#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

typedef long long ll;

ll n, k, x;
ll sum1;
vector<ll> v;


double s1(){
    ll sum2 = x*(n-1);
    ll att = sum1-sum2;
    ll mmin = 1e18, best;
    for(ll i = 0; i < n; i++){
        ll sum = v[i];
        if(abs(att-sum) < mmin){
            mmin = abs(att-sum);
            best = sum;
        }
    }
    return (1.0*abs(sum1-best-sum2))/(1.0*n-1);
}

double s2(){
    ll sum2 = x*(n-2);
    ll att = sum1-sum2;
    ll mmin = 1e18, best;
    for(ll i = 0; i < n; i++){
        for(ll j = i+1; j < n; j++){
            ll sum = v[i]+v[j];
            if(abs(att-sum) < mmin){
                mmin = abs(att-sum);
                best = sum;
            }
        }
    }
    return (1.0*abs(sum1-best-sum2))/(1.0*n-2);

}

double s3(){
    ll sum2 = x*(n-3);
    ll att = sum1-sum2;
    ll mmin = 1e18, best;
    multiset<ll> cj;
    cj.insert(v[0]+v[1]);
    for(ll i = 2; i < n; i++){ 
        auto it = cj.upper_bound(att-v[i]);
        if(it != cj.end()){
            if(abs(att-v[i]-*it) < mmin){
                mmin = abs(att-v[i]-*it);
                best = v[i]+*it;
            }
        }
        if(it != cj.begin()){
            --it;
            if(abs(att-v[i]-*it) < mmin){
                mmin = abs(att-v[i]-*it);
                best = v[i]+*it;
            }
        }
        if(it != cj.begin()){
            --it;
            if(abs(att-v[i]-*it) < mmin){
                mmin = abs(att-v[i]-*it);
                best = v[i]+*it;
            }
        }
        for(ll j = 0; j < i; j++){ cj.insert(v[i]+v[j]); }
    }
    return (1.0*abs(sum1-best-sum2))/(1.0*n-3);
}

double s4(){
    ll sum2 = x*(n-4);
    ll att = sum1-sum2;
    ll mmin = 1e18, best;
    multiset<ll> cj;
    cj.insert(v[0]+v[1]);
    for(ll i = 2; i < n; i++){
        for(ll j = i+1; j < n; j++){
            auto it = cj.upper_bound(att-v[i]-v[j]);
            if(it != cj.end()){
                if(abs(att-v[i]-v[j]-*it) < mmin){
                    mmin = abs(att-v[i]-v[j]-*it);
                    best = v[i]+v[j]+*it;
                }
            }
            if(it != cj.begin()){
                --it;
                if(abs(att-v[i]-v[j]-*it) < mmin){
                    mmin = abs(att-v[i]-v[j]-*it);
                    best = v[i]+v[j]+*it;
                }
            }
            if(it != cj.begin()){
                --it;
                if(abs(att-v[i]-v[j]-*it) < mmin){
                    mmin = abs(att-v[i]-v[j]-*it);
                    best = v[i]+v[j]+*it;
                }
            }
        }
        for(ll j = 0; j < i; j++) cj.insert(v[i]+v[j]);
    }
    return (1.0*abs(sum1-best-sum2))/(1.0*n-4);
}

int main(){
    cin >> n >> k >> x;
    v.resize(n);
    sum1 = 0;
    for(ll &x:v) cin >> x, sum1 += x;
    double ans = (1.0*abs(sum1-x*n))/(1.0*n);
    if(k >= 1) ans = min(ans, s1());
    if(k >= 2) ans = min(ans, s2());
    if(k >= 3) ans = min(ans, s3());
    if(k >= 4) ans = min(ans, s4());
    cout << fixed << setprecision(10) << ans << "\n";
}
