#include <bits/stdc++.h>

using namespace std;

#define INF 1e300

typedef double ld;

struct vp{
    int x, y;
    vp(){x=y=0;}
    vp(int xx, int yy){x=xx;y=yy;}

    bool operator<(vp a) const{return x!=a.x ? x < a.x : y < a.y;}
};

namespace  closest{
    int n;
    ld min_dist; vp x, y;
    vector<vp> S, B;

    bool cmp_y(const vp &a, const vp &b){return a.y < b.y;}

    void upd_dist(vp a, vp b){
        ld dist = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
        if(dist < min_dist){
            min_dist = dist;
            x = a; y = b;
        }
    }

    void solve(int l, int r){
        if(r-l+1 <= 3){
            for(int i = l; i <= r; i++)
                for(int j = i+1; j <= r; j++)
                    upd_dist(S[i], S[j]);
            sort(S.begin()+l, S.begin()+r+1, cmp_y);
            return;
        }

        int mid = (l+r)/2;
        solve(l, mid);
        solve(mid+1, r);

        merge(S.begin()+l, S.begin()+mid, S.begin()+mid, S.begin()+r+1, B.begin(), cmp_y);
        copy(B.begin(), B.begin()+r-l+1, S.begin()+l);

    }

    ld closest_2points(vector<vp> SS){
        S = SS; min_dist = INF; n = S.size(); B.resize(n);
        sort(S.begin(), S.end());
        solve(0, n-1);
        return min_dist;
    }
}


int main(){
    int n; cin >> n;
    vector<vp> S; 
    S.resize(n);
    for(auto &[x,y]:S) cin >> x >> y;
    cout << fixed << setprecision(15) << closest::closest_2points(S) << "\n";
    return 0;
}
