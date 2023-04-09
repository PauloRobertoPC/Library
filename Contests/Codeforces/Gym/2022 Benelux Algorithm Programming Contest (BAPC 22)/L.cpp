#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef double ld;

struct vp{
    ll x, y, z; 
    vp(){x=y=z=0;}
    vp(ll xx, ll yy, ll zz){x=xx;y=yy;z=zz;}

    bool operator<(vp a) const{return x!=a.x ? x<a.x : y!=a.y ? y<a.y : z<a.z;}
};

ld dist(vp a, vp b){
    ld xx = a.x-b.x; 
    ld yy = a.y-b.y; 
    ld zz = a.z-b.z; 
    return sqrt(xx*xx + yy*yy + zz*zz);
}

ld closest_2points(vector<vp> S){
    sort(S.begin(), S.end());
    ld d = dist(S[0], S[1]); ll p = 0;
    set<pair<ll, ll>> active; 
    for(ll i = 0 ; i < S.size(); i++){
        while(S[i].x-S[p].x > d || S[i].y-S[p].y > d) active.erase({S[p].z, p++});
        auto it = active.lower_bound({S[i].z-floor(d), 0});
        while(it != active.end() && it->first <= S[i].z+floor(d))
            d = min(d, dist(S[i], S[it->second])), it++;
        active.insert({S[i].z, i});
    }
    return d;
}

int main(){
    ll n; cin >> n;
    vector<vp> S(n);
    for(auto &[x,y,z]:S) cin >> x >> y >> z;
    cout << fixed << setprecision(15) << closest_2points(S) << "\n";
    return 0;
}
