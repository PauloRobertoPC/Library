#include <bits/stdc++.h>

using namespace std;

#define maxn 10000000000000LL

typedef long long ll;

struct segtree{
    struct node{
        ll sum;
        node *l, *r;

        node() : sum(0), l(nullptr), r(nullptr){}
    };

    node *rt;

    segtree(){ rt = new node; }

    ll merge(node *a, node *b){
        return (a == nullptr ? 0 : a->sum) + (b == nullptr ? 0 : b->sum);
    }

    void update(ll pos){
        update(pos, rt);
    }
    
    void update(ll pos, node *&root, ll l = 0, ll r = maxn){
        // cout << l << " " << r << "\n";
        if(l > pos || r < pos) return;
        if(root == nullptr) root = new node;
        if(l == pos && r == pos){
            root->sum++;
            return;
        }
        ll mid = (l+r)>>1LL;
        update(pos, root->l, l, mid);
        update(pos, root->r, mid+1, r);
    	root->sum = (root->l ? root->l->sum : 0) + (root->r ? root->r->sum : 0);
    }

    ll get(ll pos){
        return get(pos, rt);
    }
    
    ll get(ll pos, node *root, ll l = 0, ll r = maxn){
        if(root == nullptr) return 0LL;
        if(r <= pos) return root->sum;
        if(l > pos) return 0;
        ll mid = (l+r)>>1LL;
        return get(pos, root->l, l, mid) + get(pos, root->r, mid+1, r);
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    segtree seg;
    ll n; cin >> n;
    ll x, y, p = 0;
    for(ll i = 1; i <= n; i++){
        cin >> x >> y; 
        x += p; y += p;
        p = seg.get(x*x+y*y);
        seg.update(x*x+y*y);
        cout << p << "\n";
    }
    return 0;
}
