struct vp{
    int x, y;

    vp(){x=y=0;}
    vp(int xx, int yy) : x(xx), y(yy){}

    vp operator-(vp a) const{ return vp(x-a.x, y-a.y); }
    int operator^(vp a) const{ return x*a.y - y*a.x; }
    bool operator<(vp a) const{ return x != a.x ? (x<a.x) : (y<a.y); }
};

//-1, counter-clockwise
//0, colinear
//1, clockwise
int signal(vp a, vp b, vp c){
    int sg = (b-a)^(c-a);
    return (sg == 0 ? 0 : (sg > 0 ? -1 : 1));
}

//S we assume that S is sorted
//if upper then calc upper_hull else calc lower_hull
//if non_colinear then no colinear points are accepted in the convex hull
vector<vp> half_hull(vector<vp> &S, bool upper, bool non_colinear){
    int side = 1 - 2*upper;
    vector<vp> h_hull;
    for(auto p:S){
        while(h_hull.size() >= 2 && (signal(h_hull.end()[-2], h_hull.back(), p) == side
            || (non_colinear && signal(h_hull.end()[-2], h_hull.back(), p) == 0)))
            h_hull.pop_back();
        h_hull.emplace_back(p);
    }
    return h_hull;
}

//Convex hull in clockwise direction
vector<vp> convex_hull(vector<vp> &S, bool non_colinear=1){
    sort(S.begin(), S.end());
    vector<vp> upper = half_hull(S, 1, non_colinear), lower = half_hull(S, 0, non_colinear);
    for(int i = lower.size()-2; i > 0; i--) upper.emplace_back(lower[i]); 
    return upper;
}
