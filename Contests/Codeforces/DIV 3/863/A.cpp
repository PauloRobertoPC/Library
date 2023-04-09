#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string sla, a, b;
        cin >> sla >> b >> a;
        bool ok = false;
        for(int i = 0; i < a.size(); i++){
            if(a[i] < b[0]){
                for(int j = 0; j < i; j++) cout << a[j];
                cout << b;
                for(int j = i; j < a.size(); j++) cout << a[j];
                ok = true;
                break;
            }
        }
        if(!ok) cout << a << b;
        cout << "\n";
    }
    return 0;
}
