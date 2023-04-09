#include <bits/stdc++.h>

using namespace std;

int n;

int cv(int i){
    if(i > n/2) return n-i+1;
    return i;
}

int main(){
    int t; cin >> t;
    while(t--){
        int x1, y1, x2, y2;
        cin >> n >> x1 >> y1 >> x2 >> y2;
        x1 = cv(x1);
        y1 = cv(y1);
        x2 = cv(x2);
        y2 = cv(y2);
        cout << abs(min(x1, y1)-min(x2, y2)) << "\n";
    }
    return 0;
}
