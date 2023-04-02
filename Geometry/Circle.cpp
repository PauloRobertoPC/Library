typedef long double ld;
typedef long long ll;

const ld PI = acos(-1);

struct circle{
    ll x, y, r;

    circle(ll xx, ll yy, ll rr) : x(xx), y(yy), r(rr){}
};

ld area(circle A, circle B) {
	if(A.r < B.r) swap(A, B);
	ld dis = sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
	if(dis >= A.r + B.r) 
		return 0;
	if(dis <= A.r - B.r) 
		return PI * B.r * B.r;
	ld alpha = 2 * acos((dis * dis + A.r * A.r - B.r * B.r) / 2 / dis / A.r);
	ld beta = 2 * acos((dis * dis + B.r * B.r - A.r * A.r) / 2 / dis / B.r);
	return A.r * A.r * (alpha - sin(alpha)) / 2 + B.r * B.r * (beta - sin(beta)) / 2;
}
