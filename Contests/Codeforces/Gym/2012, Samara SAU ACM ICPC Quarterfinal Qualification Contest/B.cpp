#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<double> p;
vector<pair<ll, ll>> v;

double trapezio(pair<ll, ll> a, pair<ll, ll> b){
    return -((a.second+b.second)*(b.first-a.first)*1.0)/2.0;
}

double area(int i, int j){
    double a = trapezio(v[j], v[i]);
    if(i-1 < 0) return p[j-1]+a;
    return p[j-1]-p[i-1]+a;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    v.resize(n);
    for(auto &x:v){
        cin >> x.first >> x.second;
        x.first += 1e8;
        x.second += 1e8;
    }
    double a = 0.0;
    for(ll i = 0; i < n; i++){
        a += trapezio(v[i], v[(i+1)%n]); 
        p.emplace_back(a);
    }
    map<double, int> pref;
    pref[0] = -1;
    for(int i = 0; i < n; i++){
        

    }
    int o1, o2;
    double mmin = 1e18;
    for(int d = 2; n-d >= 0; d++){
        for(int i = 0; i+d < n; i++){
            double a1 = area(i, i+d);
            double a2 = a-a1;
            // cout << i+1 << " " << i+d+1 << " -> ";
            // cout << a1 << " " << a2 << "\n";
            if(abs(2*a1 - a) < mmin){
                mmin = abs(a1-a2);
                o1 = i+1;
                o2 = i+d+1;
            }
        }
    }
    cout << o1 << " " << o2 << "\n";
    return 0;
}
