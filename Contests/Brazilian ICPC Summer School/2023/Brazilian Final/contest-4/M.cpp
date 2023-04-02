#include <bits/stdc++.h>

using namespace std;

string to_str(int num){
    string s = "";
    while(num){
        s += char(num%2+'0');
        num /= 2;
    }
    while(s.size() < 31) s.push_back('0');
    reverse(s.begin(), s.end());
    return s;
}

struct Trie{
    struct no{
        int cnt;
        vector<int> next;
        no(){
            next.assign(2, -1);
            cnt = 0;
        }
    };
    vector<no> tree;
    Trie(){
        tree.emplace_back(); 
    }
    void in_out(string &s, int val){
        int curr = 0;
        tree[curr].cnt += val;
        for(char ch:s){
            if(tree[curr].next[ch-'0'] == -1){
                tree.emplace_back();
                tree[curr].next[ch-'0'] = tree.size()-1;
            }
            curr = tree[curr].next[ch-'0'];
            tree[curr].cnt += val; 
        }
    }

    int search(string &s){
        int curr = 0, ans = 0;
        for(char ch:s){
            int next_char = (ch == '1' ? 0 : 1); 
            bool um = true;
            if(tree[curr].next[next_char] == -1 || tree[tree[curr].next[next_char]].cnt == 0) next_char ^= 1, um = false;
            curr = tree[curr].next[next_char];
            ans = (ans<<1) + (um);
        }
        return ans;
    }
};

int main(){
    int q, num; cin >> q;
    char op; string snum = to_str(0); 
    Trie t; t.in_out(snum, 1);
    while(q--){
        cin >> op >> num;
        snum = to_str(num);
        if(op == '+'){
            t.in_out(snum, 1);   
        }else if(op == '-'){
            t.in_out(snum, -1);   
        }else{
            cout << t.search(snum) << "\n";
        }
    }
    return 0;
}
// Description: String - max xor with trie
