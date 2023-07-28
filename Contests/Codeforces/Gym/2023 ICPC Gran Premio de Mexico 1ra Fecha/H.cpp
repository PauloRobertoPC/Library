#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;
const int K = 26;

inline int ctoi(char ch){
    return ch-'a';
}

struct ac{
    struct node{
        vector<int> next, go;
        int dad = 0, term = 0, slink = -1, exi = -1, sz = 0;
        char dadc = '$';

        node(int d = 0, char dc = '$', int s = 0) : dad(d), dadc(dc), sz(s){
            next.assign(K, -1);
            go.assign(K, -1);
        }
    };

    vector<node> aca;

    ac(){ aca.emplace_back(); }

    void insert(string &s){
        int u = 0;
        for(char ch:s){
            int ich = ctoi(ch);
            if(aca[u].next[ich] == -1){
                aca[u].next[ich] = aca.size();
                aca.emplace_back(u, ch, aca[u].sz+1);
            }
            u = aca[u].next[ich];
        }
        aca[u].term = 1;
    }

    int go(int u, int ch){
        if(aca[u].go[ch] != -1) return aca[u].go[ch];
        if(aca[u].next[ch] != -1) return aca[u].go[ch] = aca[u].next[ch];
        return aca[u].go[ch] = (u == 0 ? 0 : go(slink(u), ch));
    }

    int slink(int u){
        if(aca[u].slink != -1) return aca[u].slink;
        return aca[u].slink = (u == 0 || aca[u].dad == 0 ? 0 : go(slink(aca[u].dad), ctoi(aca[u].dadc)));
    }

    int exi(int u){
        int link = slink(u);
        if(aca[u].exi != -1) return aca[u].exi;
        return aca[u].exi = (link == 0 || aca[link].term  ? link : exi(link));
    }

    //O(|s|*sqrt(|aca|))
    int ways_to_make_a_word(string s){
        s = '$'+s;
        vector<int> dp(s.size(), 0);
        dp[0] = 1; int curr = 0, w;
        for(int i = 1; i < s.size(); i++){
            w = curr = go(curr, ctoi(s[i]));
            while(w){
                if(aca[w].term)
                    dp[i] = (dp[i] + dp[i-aca[w].sz])%mod;
                w = exi(w);
            }
        }
        return dp.back();
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ac aca;
    string s, t;
    int k; cin >> k;
    while(k--){
        cin >> t;
        aca.insert(t);
    }
    cin >> s;
    cout << aca.ways_to_make_a_word(s) << "\n";
    return 0;
}
