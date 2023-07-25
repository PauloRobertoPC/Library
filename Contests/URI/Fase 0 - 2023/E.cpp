#include <bits/stdc++.h>

using namespace std;

#define maxn int(1e4+10)

int n;
int v[maxn], e[maxn];

bool f(int mid){
    map<int, int> freq;
    for(int i = 0; i < n; i++) freq[e[i]]++;
    for(int i = 0; i < n; i++){
        int erro = abs(v[i]-mid);
        if(!freq[erro]) return false;
        --freq[erro];
    }
    return true;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) cin >> e[i];
    sort(v, v+n);
    // for(int i = 0; i < n; i++) cout << v[i] << " "; cout << "\n";
    set<int> ans;
    int mmax = *max_element(e, e+n);
    // cout << v[0]-mmax << " " << v[0]+mmax << " " << v[n-1]-mmax << " " << v[n-1]+mmax << "\n";
    if(v[0] - mmax >= 1 && f(v[0]-mmax))
        ans.insert(v[0]-mmax);
    if(v[n-1] - mmax >= 1 && f(v[n-1]-mmax))
        ans.insert(v[n-1]-mmax);
    if(v[0] + mmax <= 1e9 && f(v[0]+mmax))
        ans.insert(v[0]+mmax);
    if(v[n-1] + mmax <= 1e9 && f(v[n-1]+mmax))
        ans.insert(v[n-1]+mmax);
    for(int x:ans) cout << x << "\n";
    return 0;
}
