#include <bits/stdc++.h>

using namespace std;

int main(){
    long double p, q;
    cin >> p >> q;
    p /= 100, q /= 100;
    cout << fixed << setprecision(10) <<  ((p*p + q*q)/(p+q)) << "\n";
    return 0;
}
