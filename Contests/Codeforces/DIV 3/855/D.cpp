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

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        StringHashing hs(s);
        set<uint64_t> cj;
        cj.insert(hs.getValue(2, n-1));
        cj.insert(hs.getValue(0, n-3));
        for(int i = 1; i+2 < n; i++){
            int a = 0, b = i-1; 
            int l = i+2, r = n-1; 
            uint64_t p1 = hs.getValue(a, b);
            uint64_t p2 = hs.getValue(l, r);
            p1 = hs.modMul(p1, hs.p[r-l+1]);
            cj.insert((p1+p2)%hs.MOD);
        }
        cout << cj.size() << "\n";
    }
    return 0;
}
