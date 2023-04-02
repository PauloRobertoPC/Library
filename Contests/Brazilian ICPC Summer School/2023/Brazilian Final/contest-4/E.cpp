#include <algorithm>
#include <bits/stdc++.h>
#include <ios>

using namespace std;

#define INF int(1e9)

set<int> cj;

struct B_Tree{
    struct node{
        int n, id;
        node *parent;
        vector<int> val;
        vector<node*> children;

        node(){
            n = 0;
            parent = nullptr;
            val.assign(1, INF);
            children.assign(1, nullptr);
        }
    };
    
    int id;
    node *root; 
    
    B_Tree(){
        root = new node();
        root->id = id++;
    }
    
    int find_point(node *curr, int k){
        int i = 0;
        for(int x:curr->val){
            if(k < x) break; 
            ++i;
        }
        return i; 
    }

    void include(node *curr, int k){
        ++curr->n;
        int pos = find_point(curr, k);
        curr->val.insert(curr->val.begin()+pos, k);
    }

    void up_node(node *no){
        //Removing in No
        node *dad = no->parent;
        int rm = no->val[1];
        node *l = new node(); include(l, no->val[0]); l->parent = dad;
        l->id = id++;
        node *r = new node(); include(r, no->val[2]); r->parent = dad;
        r->id = id++;
        if(no->children.size() != 1){
            no->children[1]->parent = l; no->children[0]->parent = l;
            l->children.insert(l->children.begin(), no->children[1]); l->children.insert(l->children.begin(), no->children[0]);
            no->children[3]->parent = r; no->children[2]->parent = r;
            r->children.insert(r->children.begin(), no->children[3]); r->children.insert(r->children.begin(), no->children[2]);
        }
        // delete no;
        
        //Adding in Parent
        int pos = find_point(dad, rm);
        dad->children.insert(dad->children.begin()+pos, r);
        dad->children.insert(dad->children.begin()+pos, l);
        if(dad->n != 0)
            dad->children.erase(dad->children.begin()+pos+2); 
        ++dad->n;
        dad->val.insert(dad->val.begin()+pos, rm);
    }
    
    void add(int k){
        node *curr = root;
        while(curr->children.size() != 1) curr = curr->children[find_point(curr, k)]; 
        if(curr->n == 3){
            split(curr); 
            add(k);
        }else{
            include(curr, k);
        }
    }

    void split(node *no){
        if(no->n < 3) return;  
        if(no->parent == nullptr){
            root = new node();     
            no->parent = root;
        }
        if(no->parent->n == 3){
            split(no->parent);
        }    
        up_node(no);
    }

    void dfs(){
        dfs(root);
    }

    void dfs(node *curr, int h = 0){
        if(curr->children.size() == 1) cj.insert(h);
        for(int i = 0; i < curr->val.size(); i++)
            if(curr->val[i] != INF) cout << curr->val[i] << " ";
        cout << "\n";
        for(int i = 0; i < curr->children.size(); i++)
            if(curr->children[i] != nullptr) dfs(curr->children[i], h+1);
    }
    

};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int c; cin >> c;
    for(int caso = 1; caso <= c; caso++){ 
        cout << "Case #" << caso << ":\n";
        B_Tree t;
        int n; cin >> n;
        while(n--){
            int num; cin >> num;
            t.add(num);
        }
        cj.clear();
        t.dfs();
        assert(cj.size() == 1);
    }
    return 0;
}
