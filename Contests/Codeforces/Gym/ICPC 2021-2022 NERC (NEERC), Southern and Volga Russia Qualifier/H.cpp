#include <bits/stdc++.h>

using namespace std;

#define maxn 1010

typedef long long ll;

ll n, m, tot;
bool M[maxn][maxn];
int P[maxn][maxn][2];

bool ok(ll i, ll j){
    return i >= 1 && i <= n && j >= 1 && j <= m;
}

ll build(ll i, ll j, ll dx, ll dy, ll op){
    if(P[i][j][op] != 0) return P[i][j][op];
    if(ok(i+dx, j+dy))
        return P[i][j][op] = 1+build(i+dx, j+dy, dy, dx, op^1);
    return P[i][j][op] = 0;
}

tuple<ll, ll, ll> beg(ll i, ll j, ll dx, ll dy, ll op){
    if(ok(i+dx, j+dy))
        return beg(i+dx, j+dy, dy, dx, op^1);
    return {i, j, op};
}

ll solve(ll i, ll j, ll dx, ll dy, ll op){
    if(M[i][j]){
        if(ok(i+dx, j+dy)) 
            solve(i+dx, j+dy, dy, dx, op^1);
        return -1;
    }
    if(ok(i+dx, j+dy)){
        tot -= P[i][j][op];
        P[i][j][op] = 1+solve(i+dx, j+dy, dy, dx, op^1);
        tot += P[i][j][op];
        return P[i][j][op];
    }

    tot -= P[i][j][op];
    return P[i][j][op] = 0;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll q;
    cin >> n >> m >> q;
    tot = n*m;
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= m; j++){
            if(!P[i][j][0]) build(i, j, 0, 1, 0);
            if(!P[i][j][1]) build(i, j, 1, 0, 1);
            tot += P[i][j][0]+P[i][j][1];
        }
    }
    while(q--){
        ll i, j, a, b, x, y, op, dx, dy; cin >> i >> j;
        M[i][j] ^= 1;
        if(M[i][j]){
            tot -= P[i][j][0]+P[i][j][1];
            --tot;
            P[i][j][0] = P[i][j][1] = 0;
        }else ++tot;

        tie(a, b, op) = beg(i, j, 0, -1, 1);
        solve(a, b, op!=0, op==0, op);

        tie(a, b, op) = beg(i, j, -1, 0, 0);
        solve(a, b, op!=0, op==0, op);

        cout << tot << "\n";
    }
    return 0;
}
