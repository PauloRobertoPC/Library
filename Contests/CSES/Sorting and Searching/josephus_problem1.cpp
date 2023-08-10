#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    list<int> l;
    for(int i = 1; i <= n; i++) l.emplace_back(i);
    auto it = l.begin();
    for(int i = 1; i <= n; i++){
        ++it;
        if(it == l.end()) it = l.begin();

        auto aux = it;
        ++it;
        if(it == l.end()) it = l.begin();

        cout << *aux << "\n";
        l.erase(aux);
    }
    return 0;
}
