#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll pref[20];

void precomp(){
    pref[0] = 1;
    for(ll i = 1, pot = 1; pot <= ll(1e16); pot *= 10, i++)
        pref[i] = pref[i-1] + (pot*10-pot)*i;
}

ll query(ll pos){
    if(pos == 1) return 1;
    ll i = 0, pot = 1;
    for(; pref[i] < pos; i++, pot*=10);
    pot /= 10;
    ll lack = pos - pref[i-1];
    ll walk = lack/i;
    ll walk_number = lack%i;
    ll number = pot+walk;
    return to_string(number)[walk_number]-'0';
}

int main(){
    precomp();
    ll t; cin >> t;
    while(t--){
        ll p; cin >> p;
        cout << query(p) << "\n";
    }
    return 0;
}
