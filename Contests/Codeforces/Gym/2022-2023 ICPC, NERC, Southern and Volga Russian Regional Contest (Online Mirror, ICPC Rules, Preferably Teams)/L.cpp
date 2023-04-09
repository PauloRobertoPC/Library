#include <bits/stdc++.h>
#include <queue>

using namespace std;

int n, m, k;
vector<int> holi;
vector<vector<int>> work;
vector<queue<int>> projects;
map<string, int> parse;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<string> ss = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    for(int i = 0; i < ss.size(); i++) parse[ss[i]] = i;

    cin >> n >> m >> k;

    work.resize(n);
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        while(t--){
            string s; cin >> s;
            work[i].emplace_back(parse[s]);
        }
    }

    holi.resize(m);
    for(int &x:holi) cin >> x;

    projects.resize(k);
    for(int i = 0; i < k; i++){
        int t; cin >> t;
        while(t--){
            int x; cin >> x;
            projects[i].push(x-1);
        }
    }

    vector<map<int, multiset<int>>> table(7);
    for(int i = 0; i < k; i++){
        int x = projects[i].front();
        for(int wk:work[x]) table[wk][x].insert(i);
    }

    vector<int> ans(k);
    for(int s = 0, d = 1, ch = 0, w = k; w; s++, s %= 7, d++){
        if(ch < m && d == holi[ch]){
            ++ch;
            continue;
        }
        vector<pair<int, int>> rem;
        for(auto &[x, op]:table[s]){
            int p = *op.begin();
            projects[p].pop();
            if(projects[p].empty()){
                ans[p] = d;
                --w;
            }
            rem.emplace_back(x, p);
        }

        for(auto &[x, p]:rem){
            if(!projects[p].empty()){
                int x2 = projects[p].front();
                for(int wk:work[x2]) table[wk][x2].insert(p);
            }
            for(int wk:work[x]){
                table[wk][x].erase(table[wk][x].find(p));
                if(table[wk][x].empty())
                    table[wk].erase(x);
            }
        }
    }

    for(int x:ans) cout << x << " "; cout << "\n";

    return 0;
}
