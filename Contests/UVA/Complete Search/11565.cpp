#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        bool sol = false;
        int a, b, c; cin >> a >> b >> c;
        for(int x = -22; x <= 22 && !sol; x++){
            if(x*x > c) continue;
            for(int y = -100; y <= 100 && !sol; y++){
                if(y == x || x*x + y*y > c) continue;
                for(int z = -100; z <= 100 && !sol; z++){
                    if(z == x || z == y) continue;
                    if(x+y+z == a && x*y*z == b && x*x+y*y+z*z == c){
                        cout << x << " " << y << " " << z << "\n";
                        sol = true;
                    }
                }
            }
        }
        if(!sol) cout << "No solution.\n";
    }
    return 0;
}
