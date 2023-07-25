#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct vp{
    ll x, y, val;
    vp(){}
    vp(ll xx, ll yy){x=xx;y=yy;}
    vp(ll xx, ll yy, ll vval){x=xx;y=yy;val=vval;}

    vp operator-(){return vp(-x,-y);}
    vp operator-(vp a){return vp(x-a.x,y-a.y);}
    ll operator*(vp a){return x*a.x+y*a.y;}
    ll operator^(vp a){return x*a.y-y*a.x;}
    vp operator!(){ll gcd = __gcd(x, y); return vp(x/gcd, y/gcd);}
    ll region(){return 1 - (y>0 || (y==0 && x>0));}
    bool operator<(vp a){return x < a.x;}
    static bool cmp_angle(vp a, vp b){
        if(a.region() != b.region()) return a.region() < b.region();
        if((a^b) != 0) return (a^b) > 0;
        return (a*a < b*b);
    }
};

int main(){
    ll n;
    cin >> n;
    vector<vp> v(n);
    for(auto &[x, y, val]:v) cin >> x >> y >> val;
    sort(v.begin(), v.end(), vp::cmp_angle);
    vector<map<vp, int>> adj;
    for(int i = 1; i < n; i++){
        for(int j = i-1; j >= 0; j--){
            vp aux = v[i]-v[j];
            aux = !aux;
            adj[i][aux] = (adj[j].count(aux) ? j : adj[j][aux]);
            adj[i][aux] = (adj[j].count(-aux) ? j : adj[j][-aux]);
            adj[i][-aux] = adj[i][aux];
        }
    }
    set<vp> vv;
    for(int i = 0; i < n; i++){
        for(auto [dir, prev]:adj[i]){
            cout << i << " ";
            while(adj[prev].count(dir)){
                cout << prev << " "; 
                prev = adj[prev][dir];
            }cout << "\n";
        }
    }
    // for(int i = 1; i < n; i++){
    //     for(int j = i-1; j >= 0; j--){
    //         vp aux = v[i]-v[j];
    //         aux = !aux;
    //         adj[i][aux] = v[i].val+(adj[j].count(aux) ? v[j].val : adj[j][aux]);
    //         adj[i][aux] = v[i].val+(adj[j].count(-aux) ? v[j].val : adj[j][-aux]);
    //         adj[i][-aux] = adj[i][aux];
    //     }
    // }
    return 0;
}
