#include <bits/stdc++.h>
#define maxn int(2e4+5)
using namespace std;

int ft[maxn];

int lsone(int x){
    return x&(-x);
}

void update(int l, int v){
    int answ = 0;
    for(;l<maxn;l+=lsone(l)){
        ft[l] = max(ft[l],v);
    }
}

int get(int l){
    int answ = 0;
    for(;l;l-=lsone(l)){
        answ = max(ft[l],answ);
    }
    return answ;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;

    while(t--){
        memset(ft,0,sizeof(ft));

        int n; cin >> n;
        vector<pair<int, int>> v(n);
        for(auto &par:v) cin >> par.first >> par.second, par.second = -par.second;

        sort(v.begin(),v.end());
        vector<int> arr;
        for(auto p:v)
            arr.push_back(-p.second);
        reverse(arr.begin(),arr.end());

        for(int i=0;i<n;i++){
            update(arr[i],get(arr[i])+1);
        }

        cout << get(maxn-1) << "\n";
    }
    return 0;
}
