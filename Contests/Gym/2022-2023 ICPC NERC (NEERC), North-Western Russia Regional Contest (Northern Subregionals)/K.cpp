#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct point2d{
    ll x, y;

    point2d() : x(0), y(0) {};

    point2d(ll x, ll y) : x(x), y(y) {};

    point2d operator~(){
        point2d ans(this->x, this->y);
        ll gcd = __gcd(ans.x, ans.y); gcd=abs(gcd);
        ans.y /= gcd; ans.x /= gcd;
        //Direction matters, so you cannot change the direction with the commented code below
        // if(ans.y < 0) ans.y = -ans.y, ans.x = -ans.x;
        // else if(ans.y == 0) ans.x = abs(ans.x);
        return ans;
    }
};

ll operator^(const point2d& a, const point2d& b){
    return a.x*b.y-a.y*b.x;
}

point2d operator-(const point2d& a, const point2d& b){
    return point2d(a.x-b.x,a.y-b.y);
}

bool operator<(const point2d& a, const point2d& b){
    pair<ll, ll> aa = {a.x, a.y};
    pair<ll, ll> bb = {b.x, b.y};
    return (aa < bb);
}

struct line{
    point2d a, b;

    line();

    line(point2d a, point2d b) : a(a), b(b) { 
        if(a.x>b.x) swap(a,b);
    };
};

bool in(ll a, ll l, ll r){
    return a >= min(l, r) && a <= max(l,r);
}

bool in(line l, point2d o){
    if(o.x == l.a.x && o.y == l.a.y) return false;
    if(o.x == l.b.x && o.y == l.b.y) return false;
    if(in(o.x, l.a.x,l.b.x) && in(o.y, l.a.y,l.b.y))
        return (((o-l.a)^(o-l.b)) == 0);
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;

    while(t--){
        ll n;
        vector<line> arr;
        map<point2d,vector<line>> mp;

        cin >> n;
        for(ll i=0;i<n;i++){
            ll a, b, c, d;
            cin >> a >> b >> c >> d;
            arr.push_back(line(point2d(a,b),point2d(c,d)));
            mp[point2d(a,b)].push_back(arr.back());
            mp[point2d(c,d)].push_back(line(point2d(c,d),point2d(a,b)));
        }

        ll answ = 0;

        for(auto [C,vec] : mp){
            for(auto s:arr){
                if(in(s,C)==0) continue;
                ll positivo = 0, negativo = 0;
                map<point2d, ll> colineares;
                point2d v1 = (s.b-s.a);
                for(line l:vec){
                    point2d v2 = (l.b-l.a);
                    ll val = v1^v2;
                    positivo += (val > 0);
                    negativo += (val < 0);
                    if(val)
                        ++colineares[(~v2)]; 
                }
                answ += (positivo*(positivo-1))/2;
                answ += (negativo*(negativo-1))/2;
                for(auto [ponto, tot]:colineares)
                    answ -= (tot*(tot-1))/2;
            }
        }
        cout << answ <<"\n";
    }
    return 0;
}
//  Description: Geometry - Cross Product
