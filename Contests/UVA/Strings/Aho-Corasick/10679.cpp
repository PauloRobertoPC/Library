#include <bits/stdc++.h>

using namespace std;

const int K = 52; // Number of characters in text

inline int ctoi(char ch){
    return (ch >= 'a' ? ch-'a'+26 : ch-'A');
}

struct ac{
    struct node{
        vector<int> nxt, go;
        int term = 0, dad = -1, exi = -1, slink = -1;
        int occ = 0; //occurence of this node when the text is proccesed
        char dadc;
        vector<int> idx; //index of terminal strings in this node

        node(int _dad=0, char _dadc=0) : nxt(K, -1), go(K, -1), dad(_dad), dadc(_dadc){}
    };

    vector<node> aca; // Aho-Corasick Automaton
    vector<int> ans;

    ac(){ aca.emplace_back(); }

    void insert(string &s, int id){
        int curr = 0;
        for(auto ch:s){
            int ic = ctoi(ch);
            if(aca[curr].nxt[ic] == -1){
                aca[curr].nxt[ic] = aca.size();
                aca.emplace_back(curr, ic);
            }
            curr = aca[curr].nxt[ic];
        }
        aca[curr].term = 1; aca[curr].idx.emplace_back(id);
    }

    int go(int curr, int ic){
        if(aca[curr].go[ic] != -1) return aca[curr].go[ic];
        if(aca[curr].nxt[ic] != -1) return aca[curr].go[ic] = aca[curr].nxt[ic];
        return aca[curr].go[ic] = (curr == 0 ? 0 : go(slink(curr), ic));
    }

    int slink(int curr){
        if(aca[curr].slink != -1) return aca[curr].slink;
        return aca[curr].slink = (curr == 0 || aca[curr].dad == 0 ? 0 : go(slink(aca[curr].dad), aca[curr].dadc));
    }

    int exi(int curr){
        int link = slink(curr);
        if(aca[curr].exi != -1) return aca[curr].exi;
        return aca[curr].exi = (link == 0 || aca[link].term ? link : exi(link));

    }

    void proccess(string &s){
        ans.assign(aca.size(), 0);
        int curr = 0;
        for(char ch:s){
            int ic = ctoi(ch);
            curr = go(curr, ic);
            for(int terminal = curr; terminal; terminal = exi(terminal))
                ++aca[terminal].occ;
        }
        for(int i = 0; i < aca.size(); i++)
            for(int id:aca[i].idx)
                ans[id] += aca[i].occ;
    }
};

int main(){
    int t; cin >> t;
    while(t--){
        ac aca;
        string s; cin >> s;
        int tt; cin >> tt;
        for(int i = 0; i < tt; i++){
            string p; cin >> p;
            aca.insert(p, i);
        }
        aca.proccess(s);
        for(int i = 0; i < tt; i++) cout << (aca.ans[i] != 0 ? 'y' : 'n') << "\n";
    }
    return 0;
}
