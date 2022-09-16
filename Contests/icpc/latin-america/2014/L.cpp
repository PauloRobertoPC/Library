#include <bits/stdc++.h>

using namespace std;

tuple<int, int, int> extended_euclides(int a, int b){
    int x = 1, y = 0, x1 = 0, y1 = 1;
    while(b){
        int q = a/b;
        tie(x, x1) = make_tuple(x1, x - q*x1);
        tie(y, y1) = make_tuple(y1, y - q*y1);
        tie(a, b) = make_tuple(b, a - q*b);
    }
    return {a, x, y};
}

tuple<int, int, int, int> diophantine(int a, int b, int c){
    int g, x, y; tie(g, x, y) = extended_euclides(abs(a), abs(b));
    if(c%g) return {0, 0, 0, g};
    x = x*(c/g);
    y = y*(c/g);
    if(a < 0) x = -x;
    if(b < 0) y = -y;
    return {1, x, y, g};
}

int modular_inverse(int a, int m){
    int ok, x, y, g; tie(ok, x, y, g) = diophantine(a, -m, 1);
    if(!ok) return -1; //Don't exist a modular inverse for non-coprime numbers
    x = (((x%m)+m)%m);
    return x;
}

int main(){

    return 0;
}
