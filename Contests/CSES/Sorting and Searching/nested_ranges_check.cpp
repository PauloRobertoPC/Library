#include <bits/stdc++.h>

using namespace std;

struct BIT{
    int maxn;
    vector<int> bit;

    BIT(int n) : maxn(n+10), bit(n+10, 0){}

    void update(int pos, int val){
        for(; pos < maxn; pos += (pos&(-pos)))
            bit[pos] += val;
    }

    int get(int pos){
        int sum = 0;
        for(; pos > 0; pos -= (pos&(-pos)))
            sum += bit[pos];
        return sum;
    }

    int get(int l, int r){
        return get(r)-get(l-1);
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> ans1(n, 0), ans2(n, 0);
    map<int, int> compress;
    vector<array<int, 4>> v;
    for(int i = 0, l, r; i < n; i++){
        cin >> l >> r;
        compress[l];
        compress[r];
        v.push_back({l, 0, r, i});
        v.push_back({r, 1, l, i});
    }

    sort(v.begin(), v.end());
    int c = 1;
    for(auto &[key, value]:compress) value = c++;
    for(auto &[a, op, b, d]:v) a = compress[a], b = compress[b];

    BIT contain(compress.size());
    BIT is_contained(compress.size());

    for(int i = 0, j = 0; i < 2*n; j = i){
        while(j < 2*n-1 && v[j][0] == v[j+1][0]){
            if(v[j][1]) contain.update(v[j][2], 1), ans2[v[j][3]] = is_contained.get(v[j][2])-1;
            else is_contained.update(v[j][0], 1);
            ++j;
        }
        if(v[j][1]) contain.update(v[j][2], 1), ans2[v[j][3]] = is_contained.get(v[j][2])-1;
        else is_contained.update(v[j][0], 1);
        while(i < 2*n && i <= j){
            if(v[i][1]) 
                ans1[v[i][3]] = contain.get(v[i][2], v[i][0])-1,
                is_contained.update(v[i][2], -1);
            ++i;
        }
    }

    for(int i = 0; i < n; i++) cout << int(ans1[i]!=0) << " "; cout << "\n";
    for(int i = 0; i < n; i++) cout << int(ans2[i]!=0) << " "; cout << "\n";
    return 0;
}
