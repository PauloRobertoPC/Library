#include <bits/stdc++.h>

using namespace std;

int main(){
    map<string, int> mapa;
    mapa["norte"] = 90;
    mapa["leste"] = 180;
    mapa["sul"] = 270;
    mapa["oeste"] = 360;
    string s, t;
    cin >> s >> t;
    int dist = mapa[s] - mapa[t];
    if(dist < 0) dist += 360;
    cout << min(dist, 360-dist) << "\n";
    return 0;
}
