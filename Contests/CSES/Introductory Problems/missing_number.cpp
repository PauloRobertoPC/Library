#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    set<int> cj;
    for(int i = 1; i <= n; i++) cj.insert(i);
    for(int i = 1; i < n; i++){
        int num; cin >> num;
        cj.erase(num);
    }
    cout << (*cj.begin()) << "\n";
    return 0;
}
