#include <bits/stdc++.h>

using namespace std;

string ans;

bool impar(int n, int k){
    if((n-(k-1))%2 == 0 || k-1 >= n){
        return false;
    }
    ans = "";
    for(int i = 0; i < k-1; i++) ans += "1 ";
    ans += to_string(n-(k-1));
    return true;
}

bool par(int n, int k){
    if((k-1)*2 >= n){
        return false;
    }
    ans = "";
    for(int i = 0; i < k-1; i++) ans += "2 ";
    ans += to_string(n-((k-1)*2));
    return true;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        if(n&1){
            if(impar(n, k)){
                cout << "YES\n";
                cout << ans << "\n";
            }else{
                cout << "NO\n";
            }
        }else{
            if(impar(n, k)){
                cout << "YES\n";
                cout << ans << "\n";
            }else if(par(n, k)){
                cout << "YES\n";
                cout << ans << "\n";
            }else{
                cout << "NO\n";
            }
        }
    }
    return 0;
}
