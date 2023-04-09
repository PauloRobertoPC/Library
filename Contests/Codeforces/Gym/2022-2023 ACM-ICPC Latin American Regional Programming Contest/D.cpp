#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, h, w;
    cin >> n >> h >> w;
    for(int i = 0; i < n; i++){
        char H, W;
        cin >> H >> W;
        bool res = (H == 'Y' || (!w && h)); 
        cout << (res ? 'Y' : 'N') << " ";
        w += res;
        h -= res;
        res = (W == 'Y' || (!h && w));
        cout << (res ? 'Y' : 'N') << "\n";
        h += res;
        w -= res;
    }
    return 0;
}
