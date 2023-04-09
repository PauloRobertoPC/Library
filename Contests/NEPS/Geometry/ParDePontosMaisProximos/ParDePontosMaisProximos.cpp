#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

typedef double ld;

struct vp{
    int x, y;
    vp(){x=y=0;}
    vp(int xx, int yy){x=xx;y=yy;}

    bool operator<(vp a) const{return x != a.x ? x < a.x : y < a.y;}
};

ld dist(vp a, vp b){
    ld xx = a.x-b.x;
    ld yy = a.y-b.y;
    return sqrt(xx*xx+yy*yy);
}

ld closest_2points(vector<vp> S){
    sort(S.begin(), S.end());
    int p = 0; ld d = dist(S[0], S[1]); //index of first active event and min dist
    set<pair<int, int>> active;
    for(int i = 0; i < S.size(); i++){
        while(S[i].x - S[p].x > d) active.erase({S[p].y, p++});
        auto it = active.lower_bound({S[i].y-floor(d), 0});
        while(it != active.end() && it->first <= S[i].y+floor(d))
            d = min(d, dist(S[i], S[it->second])), it++;
        active.insert({S[i].y, i});
    }
    return d;
}

int main(){
    int n; cin >> n;
    vector<vp> S(n); 
    for(auto &[x, y]:S) cin >> x >> y;
    cout << fixed << setprecision(10) << closest_2points(S) << "\n";
    return 0;
}
