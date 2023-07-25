#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll M[110][110];

int main(){
    ll n;
    cin >> n;
    ll x, y;
    cin >> x >> y;
    ll n2 = n;
    while(n2 < max(x, y)) n2 *= 2;
    for(ll i = 1; i <= n; i++)
        for(ll j = 1; j <= n; j++)
            cin >> M[i][j];
    ll tot = 0;
    while(n2 != n){
        if(x <= n2/2){
            if(y <= n2/2){
            }else{
                tot += n2/2;
                y -= n2/2;
            }
        }else{
            if(y <= n2/2){
                tot += n2/2;
            }else{
                y -= n2/2;
            }
            x -= n2/2;
        }
        n2 /= 2;
    }
    cout << M[x][y]+tot << "\n";
    return 0;
}
