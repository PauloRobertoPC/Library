#include <bits/stdc++.h>

using namespace std;

tuple<char, char> query(int i, int j){
    cout << "? " << i << " " << j << endl; 
    char a, b; cin >> a >> b;
    return {a, b};
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    while(v.size() > 1){
        vector<int> canditates;
        for(int i = 0; i+1 < v.size(); i+=2){
            char a, b; tie(a, b) = query(v[i], v[i+1]);
            if(a == '+' && b == '+') canditates.emplace_back(v[i]);
            else if(a == '+' && b == '-') canditates.emplace_back(v[i+1]);
            else if(a == '-' && b == '+') canditates.emplace_back(v[i]);
        }
        if(v.size()&1){
            int neg = 0;
            for(int i = 0; i < v.size()-1; i++){
                char a, b; tie(a, b) = query(v[i], v.back());
                neg += (a == '-');
            }
            if(neg <= v.size()-neg-1) canditates.emplace_back(v.back());
        }
        swap(v, canditates);
    }
    vector<int> ans; 
    for(int i = 1; i <= n; i++){
        if(i == v.back()){
            ans.emplace_back(v.back());
            continue;
        }
        char a, b; tie(a, b) = query(i, v.back());
        if(b == '+') ans.emplace_back(i);
    }
    cout << "! " << ans.size() << " ";
    for(int x:ans) cout << x << " ";
    cout << endl;
    return 0;
}
