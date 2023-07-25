#include <bits/stdc++.h>

using namespace std;


int main(){
    vector<string> fib = {"b", "a"};
    cout << fib[0] << "\n";
    cout << fib[1] << "\n";
    for(int i = 2; i < 15; i++){
        fib.push_back(fib[i-1]+fib[i-2]);
        cout << fib.back() << "\n";
    }
    return 0;
}
