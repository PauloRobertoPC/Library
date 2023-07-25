#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct vp{
    ll x, y;

    vp(){x=y=0;}
    vp(ll xx, ll yy){x=xx; y=yy;}

    vp operator+(vp a){return vp(x+a.x, y+a.y);}
    vp operator-(vp a){return vp(x-a.x, y-a.y);}
    vp operator*(ll a){return vp(x*a, y*a);}
    ll operator*(vp a){return x*a.x + y*a.y;}
    ll operator^(vp a){return x*a.y - y*a.x;}
    bool operator<(vp a){return x!=a.x ? x<a.x : y<a.y;}

    bool region_value(){return 1 - (y>0 || (y==0 && x>0));}

    static bool cmp_angle(vp a, vp b){
        if(a.region_value() != b.region_value()) return a.region_value() < b.region_value();
        if((a^b) != 0) return (a^b) > 0;
        return a*a < b*b;
    }

    static ld dist(vp a, vp b){return sqrt((b-a)*(b-a));}
};

int main(){
    int n;
    cin >> n;
    vector<vp> v(n);
    for(auto &[x, y]:v) cin >> x >> y;
    sort(v.begin(), v.end(), vp::cmp_angle);
    for(auto [x, y]:v) cout << x << " " << y << "\n";
    return 0;
}
