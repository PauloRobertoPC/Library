#include <bits/stdc++.h>

using namespace std;

int n, lim;

void print(int num){
    for(int i = n-1; i+1; i--)
        cout << ((num&(1<<i)) != 0 ? 1 : 0);
    cout << "\n";
}

int main(){
    cin >> n; lim = 1<<n;
    vector<int> base = {0, 1};
    int c = 1;
    while(base.size() != lim){
        vector<int> aux1 = base;  
        vector<int> aux2 = base;  
        for(int &x:aux2) x |= (1<<c);

        base.clear();
        for(int &x:aux1) base.emplace_back(x);
        reverse(aux2.begin(), aux2.end());
        for(int &x:aux2) base.emplace_back(x);

        ++c;
    }
    for(int &x:base) print(x);
    return 0;
}
