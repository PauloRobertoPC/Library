#include <bits/stdc++.h>

using namespace std;

typedef double ld;

map<char, ld> ag;
map<char, vector<pair<ld, ld>>> corb_right;

int direction(char d, ld pos){
    for(auto [l, r]:corb_right[d])
        if(l <= pos && pos <= r)
            return 1;
    return -1;
}

ld calc_angle(string &s){
    ld curr = ag[s.back()], piece = 90.0;
    for(int i = s.size()-2; i >= 0; i--, piece /= 2){
        curr += direction(s[i], curr)*(piece/2.0);
        if(curr >= 360.0) curr -= 360;
        if(curr < 0.0) curr += 360;
    }
    return curr;
}

int main(){
    string ds = "NESW";
    for(int i = 0, aux = 0; aux < 360; aux += 90, i++) ag[ds[i]] = aux;

    corb_right['N'].emplace_back(180.0, 360.0);

    corb_right['E'].emplace_back(270.0, 360.0);
    corb_right['E'].emplace_back(0.0, 90.0);

    corb_right['S'].emplace_back(0.0, 180.0);

    corb_right['W'].emplace_back(90.0, 270.0);

    string s, t; cin >> s >> t;
    ld ag = abs(calc_angle(s)-calc_angle(t));
    cout << fixed << setprecision(10) << min(ag, 360.0-ag) << "\n";
    return 0;
}
