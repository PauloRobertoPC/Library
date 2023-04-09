#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n, p, h;
    cin >> n >> p >> h;
    deque<char> dq;
    for(int i = n-1; i >= 0; i--){
        if(h <= (1LL<<i)){
            dq.push_front('S'); //stay
        }else{
            dq.push_front('C'); //change
            h  = (1LL<<(i+1)) - h + 1;
        }
    }
    ll sz = (1LL<<(n-1));
    for(char ch:dq){
        if(ch == 'C'){
            if(p > sz){
                cout << 'R';
                p = 2*sz-p+1;
            }else{
                cout << 'L';
                p = sz-p+1;
            }
        }else{
            if(p > sz){
                cout << 'L';
                p -= sz;
            }else{
                cout << 'R';
            }
        }
        sz >>= 1;
    }
    cout << "\n";
    return 0;
}
