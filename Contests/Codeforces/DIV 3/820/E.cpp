#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll b = 2, val1, val2;
    for(ll i = 0; i < 25; i++){
        cout << "? 1 " << b << endl;
        cin >> val1;
        if(val1 == -1){
            cout << "! " << b-1 << endl; 
            return 0; 
        }
        cout << "? " << b << " 1" << endl;
        cin >> val2;
        if(val1 != val2){
            break;
        }
        ++b;
    }
    cout << "! " << val1+val2 << endl; 
    return 0;
}
