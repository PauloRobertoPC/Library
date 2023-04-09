#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct vp{
    ll x, y;
    
    vp(){x=y=0;}
    vp(ll xx, ll yy) : x(xx), y(yy){}

    vp operator+(vp a) const{ return vp(x+a.x, y+a.y); }
    vp operator-(vp a) const{ return vp(x-a.x, y-a.y); }
    ll operator*(vp a) const{ return x*a.x + y*a.y; }
    ll operator^(vp a) const{ return x*a.y - y*a.x; }
    bool operator<(vp a) const{ return x != a.x ? (x<a.x) : (y<a.y); }
};

//-1, counter-clockwise
//0, colinear
//1, clockwise
ll direction_wise(vp a, vp b, vp c){
    ll sg = (b-a)^(c-a);
    return (sg == 0 ? 0 : (sg > 0 ? -1 : 1));
}

//S we assume that S is sorted
//if upper then calc upper_hull else calc lower_hull
vector<vp> half_hull(vector<vp> &S, bool upper){
    ll side = 1 - 2*upper;
    vector<vp> h_hull;
    for(auto p:S){
        while(h_hull.size() >= 2 && direction_wise(h_hull[h_hull.size()-2], h_hull.back(), p) == side)
            h_hull.pop_back();
        h_hull.emplace_back(p);
    }
    return h_hull;
}

//Convex hull in clockwise direction
vector<vp> convex_hull(vector<vp> &S){
    sort(S.begin(), S.end());
    vector<vp> upper = half_hull(S, 1), lower = half_hull(S, 0);
    for(ll i = lower.size()-2; i > 0; i--) upper.emplace_back(lower[i]); 
    return upper;
}

int main(){
    ll n;
    while(cin >> n, n){
        vector<vp> S(n); 
        for(auto &[x, y]:S) cin >> x >> y;
        int ans = 0;
        do{
            vector<vp> ch = convex_hull(S);
            auto hull = convex_hull(S);   
            set<vp> hull_set; 
            for(auto v:hull) hull_set.insert(v);
            vector<vp> S2; 
            for(auto v:S) if(!hull_set.count(v)) S2.emplace_back(v);
            S = S2;
            ++ans;
        }while(S.size() > 2);
        cout << (ans&1 ? "Take this onion to the lab!" : "Do not take this onion to the lab!") << "\n";
    }
    return 0;
}

// Description: Geometry - Convex Hull
