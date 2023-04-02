#include <bits/stdc++.h>

using namespace std;

class Bit2d{
private:
    typedef long long t_bit;
    vector<vector<t_bit>> bit;
    int nBit, mBit;
public:
    Bit2d(int n, int m){
        nBit = n;
        mBit = m;
        bit.resize(nBit + 1, vector<t_bit>(mBit + 1, 0));
    }
    //1-indexed
    t_bit get(int i, int j){
        t_bit sum = 0;
        for (int a = i; a > 0; a -= (a & -a))
            for (int b = j; b > 0; b -= (b & -b))
                sum += bit[a][b];
        return sum;
    }
    //1-indexed
    t_bit get(int a1, int b1, int a2, int b2){
        return get(a2, b2) - get(a2, b1 - 1) - get(a1 - 1, b2) + get(a1 - 1, b1 - 1);
    }
    //1-indexed [i, j]
    void add(int i, int j, t_bit value){
        for (int a = i; a <= nBit; a += (a & -a))
            for (int b = j; b <= mBit; b += (b & -b))
                bit[a][b] += value;
    }
};

int main(){
    int t; cin >> t;
    while(t--){
        int n, q; cin >> n >> q; 
        Bit2d bit(1001, 1001);
        while(n--){
            int h, w; cin >> h >> w;
            bit.add(h, w, h*w);
        }
        while(q--){
            int h1, w1, h2, w2; cin >> h1 >> w1 >> h2 >> w2;
            cout << bit.get(h1+1, w1+1, h2-1, w2-1) << "\n";
        }
    }
    return 0;
}
