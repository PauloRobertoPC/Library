#include <bits/stdc++.h>

using namespace std;

struct StringHashing{
    const uint64_t MOD = (1LL<<61) - 1;
    const int base = 31;
    uint64_t modMul(uint64_t a, uint64_t b){
        uint64_t l1 = (uint32_t)a, h1 = a>>32, l2 = (uint32_t)b, h2 = b>>32;
        uint64_t l = l1*l2, m = l1*h2 + l2*h1, h = h1*h2;
        uint64_t ret = (l&MOD) + (l>>61) + (h << 3) + (m >> 29) + ((m << 35) >> 3) + 1;
        ret = (ret & MOD) + (ret>>61);
        ret = (ret & MOD) + (ret>>61);
        return ret-1;
    }
    int getInt(char c){
        return c-'a'+1;
    }
    vector<uint64_t> hs, p;
    StringHashing(string s){
        int n = s.size();
        hs.resize(n); p.resize(n);
        p[0] = 1;
        hs[0] = getInt(s[0]);
        for(int i=1; i<n; i++){
            p[i] = modMul(p[i-1], base);
            hs[i] = (modMul(hs[i-1], base) + getInt(s[i]))%MOD;
        }
    }
    uint64_t getValue(int l, int r){
        if(l > r) return -1;
        uint64_t res = hs[r];
        if(l > 0) res = (res + MOD - modMul(p[r-l+1], hs[l-1]))%MOD;
        return res;
    }
};

int n;

int bb(StringHashing &hs, int i, int j, int t){
    int l = 0, r = t, mid;
    while(l < r-1){
        mid = (l+r)/2;
        if(j+mid-1 >= n){
            r = mid;
            continue;
        }
        if(hs.getValue(i, i+mid-1) == hs.getValue(j, j+mid-1))
            l = mid;
        else
            r = mid;
    }
    return l;
}

int main(){
    string s; int k; cin >> s >> k;
    n = s.size();
    StringHashing hs(s);
    int c = 0;
    for(int i = 0, j; i < n; i = j, c++){
        j = -1;
        int aux1, aux2;
        for(int t = 1; t <= k; t++){
            if(i+t-1 >= n) break;
            uint64_t h1 = hs.getValue(i, i+t-1);
            int l = i;
            for(; l+t-1 < n && hs.getValue(l, l+t-1) == h1; l += t);
            l = l+bb(hs, i, l, t);
            j = max(j, l);
        }
    }
    cout << c << "\n";
}
