#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin >> n;
    long long ans = 0;
    for(ll i = n, ant = 0; i >= -1; ant = i, i -= 2){
        if(i == -1){
            ans += 2;
        }else if(i == 0){
            ans += 3;
        }else{
            ans += i*6 + 6 - (i+1) - ant;
        }
    }
    cout << ans << "\n";
    return 0;
}
