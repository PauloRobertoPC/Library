#include <bits/stdc++.h>

using namespace std;

#define maxn int(1e5+10)

string s;
int seg[4*maxn];

int merge(int a, int b){ return a|b; }

void build(int node, int l, int r){
    if(l == r){
        seg[node] = (1<<int(s[l]-'a'));
        return;
    }
    int nxt = node*2, mid = (l+r)/2;
    build(nxt, l, mid);
    build(nxt+1, mid+1, r);
    seg[node] = merge(seg[nxt], seg[nxt+1]);
}

void update(int node, int l, int r, int pos, int val){
    if(l > pos || r < pos) return;
    if(l == pos && r == pos){
        seg[node] = val;
        return;
    }
    int nxt = node*2, mid = (l+r)/2;
    update(nxt, l, mid, pos, val);
    update(nxt+1, mid+1, r, pos, val);
    seg[node] = merge(seg[nxt], seg[nxt+1]);
}

int get(int node, int l, int r, int x, int y){
    if(l > y || r < x) return 0;
    if(l >= x && r <= y) return seg[node];
    int nxt = node*2, mid = (l+r)/2;
    return merge(get(nxt, l, mid, x, y), get(nxt+1, mid+1, r, x, y));
}

int main(){
    cin >> s;
    int n = s.size();
    build(1, 0, n-1);
    int q; cin >> q;
    while(q--){
        int op, l, r; cin >> op;
        char ch;
        if(op&1){
            cin >> l >> ch; --l;
            update(1, 0, n-1, l, (1<<int(ch-'a')));
        }else{
            cin >> l >> r; --l; --r;
            cout << __builtin_popcount(get(1, 0, n-1, l, r)) << "\n";
        }
    }
    return 0;
}
// Description: Data Structures - Segtree + Bitmask
