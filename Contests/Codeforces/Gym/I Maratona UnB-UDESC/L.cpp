#include <bits/stdc++.h>

using namespace std;

#define PI acos(-1)

typedef long double ld;

int main(){
    ld R, k, d;
    cin >> R >> k >> d;
    ld r = R*k;
    // cout << R << " " << r << "\n";
    ld aro_vol = PI*(R*R-r*r)*0.5;
    ld l = r*sqrt(3);
    ld tri_vol = r*r*9*sqrt(3)/32;
    cout << fixed << setprecision(10) << (aro_vol+tri_vol)*d << "\n";
    return 0;
}
