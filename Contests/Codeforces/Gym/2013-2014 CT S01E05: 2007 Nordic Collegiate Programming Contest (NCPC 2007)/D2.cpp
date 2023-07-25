#include <bits/stdc++.h>
using namespace std;

set<string> inc(string s){
    set<string> cj;
    for(int i = 0; i < s.size(); i++){
        for(int j = i; j < s.size(); j++){
            string part = s.substr(i, j-i+1);
            cj.insert(part);
            reverse(part.begin(), part.end());
            cj.insert(part);
        }
    }
    return cj;
}

string s, t;
const int inf = 100;
vector<int> dp;
int solve(int i){
    if(i==t.size())
        return 0;
    if(dp[i]!=-1)
        return dp[i];

    auto &val =  dp[i];
    val = inf;

    auto st = inc(s);
    for(auto r:st){
        if(r==t.substr(i,r.size())){
            val = min(val,1+solve(i+r.size()));
        }
    }
    st = inc(t.substr(0,i));
    for(auto r:st){
        if(r==t.substr(i,r.size())){
            val = min(val,1+solve(i+r.size()));
        }
    }   
    return val;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int caso; cin >> caso;
    while(caso--){
        cin >> s >> t;
        dp.assign(100,-1);

        int v = solve(0);
        if(v==inf){
            cout << "impossible\n";
        }
        else{
            cout <<  v << "\n";
        }        
    }
    return 0;
}
