#include <bits/stdc++.h>

using namespace std;

int main(){
    set<int> cj;
    int n; cin >> n;
    while(n--){
        int num; cin >> num;
        cj.insert(num);
    }
    cout << cj.size() << "\n";
    return 0;
}
