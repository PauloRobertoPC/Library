#include <bits/stdc++.h>

using namespace std;

bool ok(int a, int b, int x){
    return ((a+b)%2 == 0 && (a+b)/2 == x && (a^b) == x);
}

int main(){
    int t; cin >> t;
    while(t--){
        int x; cin >> x;
        long long a = x, b = 0;
        for(int i = 32; i >= 0; i--){
            if(x&(1LL<<i)){
                // x_i == a_i -> se a_i != b_i -> a^b != x then n flip
            }else if((a+b)/2 < x){
                //x_i == 0 -> a_i == b_i
                long long auxa  = a|(1LL<<i); 
                long long auxb  = b|(1LL<<i); 
                if((auxa+auxb)/2 <= x)
                    a = auxa, b = auxb;
            }
        }
        if(ok(a, b, x))
            cout << a << " " << b << "\n";
        else
            cout << "-1\n";
    }
    return 0;
}
