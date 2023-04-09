#include <bits/stdc++.h>
#include <iomanip>
#include <vector>

using namespace std;

typedef long double ld;

ld const PI = acos(-1);

struct vp{
    int x, y;

    vp(){x=y=0;}
    vp(int xx, int yy){x=xx;y=yy;}
    
    vp operator-(vp a) const{return vp(x-a.x, y-a.y);}
    int operator^(vp a) const{return x*a.y-y*a.x;}
    bool operator<(vp a) const{return x!=a.x ? x < a.x : y < a.y;} 
};

int direction_wise(vp a, vp b, vp c){
    int sg = ((b-a)^(c-a));
    return sg == 0 ? 0 : sg > 0 ? -1 : 1;
}

vector<vp> half_hull(vector<vp> &S, bool upper){
    int side = -1 + 2*upper;  
    vector<vp> h_hull;
    for(auto p:S){
        while(h_hull.size() >= 2 && direction_wise(h_hull.end()[-2], h_hull.end()[-1], p) != side) 
            h_hull.pop_back();
        h_hull.emplace_back(p);
    }
    return h_hull;
}

ld angle(vp a, vp b){
    ld x = abs(b.x-a.x); 
    ld y = abs(b.y-a.y); 
    ld rad = atan(y/x);
    return (180*rad)/PI;
}
 
int main(){
    int n; cin >> n;
    vector<vp> S(n);
    for(auto &[x, y]:S) cin >> x >> y;

    sort(S.begin(), S.end()); 
    vector<vp> up = half_hull(S, 1);

    ld ag = -1;
    for(int i = 1; i < up.size()-1; i++){
        vp p = up[i];
        ag = max(ag, angle(S[0], p));
        ag = max(ag, angle(S.back(), p));
    }
    cout << fixed << setprecision(10) << ag << "\n";

    return 0;
}
