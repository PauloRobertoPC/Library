typedef long long ll;
typedef long double ld;

ld const PI = acos(-1);

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

    static ld dist(vp a, vp b){return sqrt((b-a)*(b-a));}

    bool region_value(){return 1 - (y>0 || (y==0 && x>0));}
    static bool cmp_angle(vp a, vp b){
        if(a.region_value() != b.region_value()) return a.region_value() < b.region_value();
        if((a^b) != 0) return (a^b) > 0;
        return a*a < b*b;
    }
};

//clockwise
bool cw(vp a, vp b, vp c){ return ((b-a)^(c-a)) < 0; }

//counter_clockwise
bool ccw(vp a, vp b, vp c){ return ((b-a)^(c-a)) > 0; }

//signal
//-1 if counter_clockwise
//0 if colinear
//1 if clockwise
ll signal(vp a, vp b, vp c){
    ll cross = ((b-a)^(c-a));
    return cross == 0 ? 0 : cross > 0 ? -1 : 1;
}

struct segment{
    vp a, b;

    segment(){a = b = vp(0, 0);}
    segment(vp aa, vp bb){a=aa; b=bb;}

    static bool intersect(segment s1, segment s2){
        bool ok1 = (signal(s1.a, s1.b, s2.a) != signal(s1.a, s1.b, s2.b));
        bool ok2 = (signal(s2.a, s2.b, s1.a) != signal(s2.a, s2.b, s1.b));
        return ok1 && ok2;
    }
};

struct line{
    vp a, b;

    line(){a=b=vp(0,0);}
    line(vp aa, vp bb){a=aa; b=bb;}
};

ld distLinePoint(line l, vp p){
    vp ab = l.b-l.a, ap = p-l.a;
    return (1.0*abs(ab^ap))/vp::dist(l.a, l.b);
}

ld distSegmentPoint(segment s, vp p){
    if((s.b-s.a)*(p-s.a) < 0) return vp::dist(s.a, p);
    if((s.a-s.b)*(p-s.b) < 0) return vp::dist(s.b, p);
    return distLinePoint(line(s.a, s.b), p);
}

//vertices of polygon must be in clockwise or counter_clockwise order
ld polygon_area(vector<vp> polygon){
    ll a = 0, n = polygon.size();
    for(ll i = 0; i < n; i++)
        a += (polygon[i].y+polygon[(i+1)%n].y)*(polygon[i].x-polygon[(i+1)%n].x);
    return abs((1.0*a)/2.0);
}

struct circle{
    vp c; ll r;

    circle(){}
    circle(vp cc, ll rr){c=cc; r=rr;}

    static ld intersection_area(circle A, circle B){
        if(A.r < B.r) swap(A, B);
        ld dis = vp::dist(A.c, B.c);
        if(dis >= A.r + B.r) return 0;
        if(dis <= A.r - B.r) return PI * B.r * B.r;
        ld alpha = 2 * acos((dis * dis + A.r * A.r - B.r * B.r) / 2 / dis / A.r);
        ld beta = 2 * acos((dis * dis + B.r * B.r - A.r * A.r) / 2 / dis / B.r);
        return A.r * A.r * (alpha - sin(alpha)) / 2 + B.r * B.r * (beta - sin(beta)) / 2;
    }
};
