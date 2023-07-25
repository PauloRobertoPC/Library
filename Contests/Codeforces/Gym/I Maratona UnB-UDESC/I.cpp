#include <bits/stdc++.h>

using namespace std;

#define maxn int(1e5+10)

int n;
int v[maxn], um[maxn], zero[maxn], neg[maxn];

int qu(int l, int r){ return um[r]-um[l-1]; }
int qz(int l, int r){ return zero[r]-zero[l-1]; }
int qn(int l, int r){ return neg[r]-neg[l-1]; }

int du(int l, int r){ return qz(1, l)+qn(1, l); }
int dz(int l, int r){ return qu(r, n)+qn(r, n); }
int dn(int l, int r){ return qu(l, r)+qz(l, r); }

int calc(int l, int r){
    if(l < 1 || r > n || l > r) return maxn;
    int uu = du(1, l);
    int nn = dn(r, n);
    ++l; --r;
    if(l > r) return maxn;
    int zz = dz(l, r);
    return uu+nn+zz;
}

int ok(int tot){
    int l = n-2, r = n;
    int qtd1 = tot, qtdn = 0;
    int mmin = calc(l, r);
    while(l >= 1){
        bool dim = true;
        if(du(1, l) != qtd1) --l, dim = false;
        if(dn(r, n) != qtdn) -- r, dim = false;
        cout << l << " " << r << "\n";
        mmin = min(mmin, calc(l, r));
        if(dim){
            --qtd1; ++qtdn;
        }
    }
    cout << mmin << " " << tot << " -----\n";
    return mmin > tot;
}

int bb(){
    int l = 0, r = n+1, mid;
    while(l < r-1){
        mid = (l+r)/2;
        if(ok(mid)) r = mid;
        else l = mid;
    }
    return l;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> v[i];
    int ans = 0;
    if(v[1] != 1) ++ans, v[1] = 1;
    if(v[n] != -1) ++ans, v[n] = -1;
    for(int i = 1; i <= n; i++){
        um[i] = um[i-1]+(v[i]==1);
        zero[i] = zero[i-1]+(v[i]==0);
        neg[i] = neg[i-1]+(v[i]==-1);
    }
    // ok(5);
    // return 0;
    cout << ans+bb() << "\n";
    return 0;
}
