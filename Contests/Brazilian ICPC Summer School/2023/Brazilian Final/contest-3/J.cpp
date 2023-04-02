#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

ld dist(pair<ld, ld> a, pair<ld, ld> b){
    ld x = a.first - b.first;
    ld y = a.second - b.second;
    return sqrt(x*x + y*y);      
}

int main(){
    int n; ld r;
    cin >> n >> r;
    vector<pair<ld, ld>> v(n);
    for(auto &par:v) cin >> par.first >> par.second;
    ld acm = 0;
    for(int i = 0; i < n; i++)
        acm += dist(v[i], v[(i+1)%n]);
    acm += 2*acos(-1)*r; 
    cout << fixed << setprecision(10) << acm << "\n";
    return 0;
}
// Description: Math - Geometry + Obbservation
