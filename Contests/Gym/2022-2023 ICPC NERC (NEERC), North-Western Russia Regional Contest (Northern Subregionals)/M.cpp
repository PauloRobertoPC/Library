#include <bits/stdc++.h>

using namespace std;

#define maxn int(2e5+10)
#define INF int(1e9)

int n;
int v[maxn], aux[maxn];
pair<int, int> seg[4*maxn];

pair<int, int> combine(pair<int, int> a, pair<int, int> b){
    return {a.first+b.first, min(a.second, b.second)};
}

void build(int node = 1, int l = 0, int r = n-1){
    if(l == r){
        int fst = (aux[l] < 0 ? 0 : aux[l]*(l+1));
        seg[node] = {fst, v[l]};
        return;
    }
    int nxt=node*2, mid=(l+r)/2;
    build(nxt, l, mid);
    build(nxt+1, mid+1, r);
    seg[node] = combine(seg[nxt], seg[nxt+1]);
}

void update(int pos, int val, int node = 1, int l = 0, int r = n-1){
    if(pos < l || pos > r) return;
    if(l == pos && r == pos){
        seg[node].first += val;
        seg[node].second += val;
        v[pos] += val;
        return;
    }
    int nxt=node*2, mid=(l+r)/2;
    update(pos, val, nxt, l, mid);
    update(pos, val, nxt+1, mid+1, r);
    seg[node] = combine(seg[nxt], seg[nxt+1]);
}

int first_zero(int node = 1, int l = 0, int r = n-1){
    if(seg[node].second > 0) return -1;
    if(l == r) return r;
    int nxt=node*2, mid=(l+r)/2;
    int ans = first_zero(nxt, l, mid);
    if(ans == -1)
        ans = first_zero(nxt+1, mid+1, r);
    return ans;
}

pair<int, int> get(int x, int y, int node = 1, int l = 0, int r = n-1){
    if(l > y || r < x) return {0, INF};
    if(l >= x && r <= y) return seg[node];
    int nxt=node*2, mid=(l+r)/2;
    return combine(get(x, y, nxt, l, mid), get(x, y, nxt+1, mid+1, r));
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) aux[i] = v[i]-v[i+1];
    build();
    for(int i = 0; i < n; i++) cout << get(i, i).first << " "; cout << "\n";
    cout << first_zero() << "\n";
    cout << get(0, first_zero()-1).first << "\n";
    for(int i = 0; i < n; i++) cout << v[i] << " "; cout << "\n";
    for(int i = 0; i < n; i++) cout << aux[i] << " "; cout << "\n";
    return 0;
}
