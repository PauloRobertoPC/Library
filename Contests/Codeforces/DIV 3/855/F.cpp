#include <bits/stdc++.h>

using namespace std;

int string_parity(string &s){
    int mask = 0;
    for(auto ch:s) mask ^= (1<<int(ch-'a'));
    return mask;
}

int string_used(string &s){
    int mask = 0;
    for(auto ch:s) mask |= (1<<int(ch-'a'));
    return mask;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s; int n; cin >> n;
    vector<int> parity(n), used(n);
    for(int i = 0; i < n; i++){
        cin >> s;
        parity[i] = string_parity(s);
        used[i] = string_used(s);
    }
    long long ans = 0, c = 0, full_mask = (1<<26)-1;
    for(char rm = 'a'; rm <= 'z'; rm++, c++){
        vector<int> no_char;
        for(int j = 0; j < n; j++){
            if(used[j]&(1<<c)) continue;
            no_char.emplace_back(parity[j]);
        }
        map<int, int> freq;
        int mask_25 = full_mask^(1<<c);
        for(int nc:no_char){
            //nc^something = mask_25 -> something = nc^mask_25
            ans += freq[nc^mask_25];
            ++freq[nc];
        }
    }
    cout << ans << "\n";
    return 0;
}
