#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int x, n; cin >> x >> n; 
        int mmin = -1, mmax = -1; 
        for(int i = 0; i < n; i++){
            int pos; cin >> pos;
            int menor = min(x-pos, pos);          
            int maior = max(x-pos, pos);          
            mmin = max(mmin, menor);
            mmax = max(mmax, maior);
        }
        cout << mmin << " " << mmax << "\n";
    }
    return 0;
}
// Description: Adhoc + Observation(Ants colision = Ants following its path)
