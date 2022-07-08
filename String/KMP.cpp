// pi and count_pref: O(|s|)
// matching and macthing_conc: O(|s|+|t|)

vector<int> pi(string s){
    vector<int> p(s.size());  
    for(int i = 1, j = 0; i < s.size(); i++){
        while(j > 0 && s[j] != s[i]) j = p[j-1];
        if(s[i] == s[j]) ++j;
        p[i] = j;
    }
    return p;
}

//Find string s as a substring of t
vector<int> matching(string &s, string &t){
    vector<int> p = pi(s+"$"), match;
    for(int i = 0, j = 0; i < t.size(); i++){
        while(j > 0 && s[j] != t[i]) j = p[j-1]; 
        if(s[j] == t[i]) ++j;
        if(j == s.size()) match.emplace_back(i-s.size()+1);
    }
    return match;
}

//Find string s as a substring of t
vector<int> matching_conc(string &s, string &t){
    vector<int> p = pi(s+"#"+t), match;
    for(int i = 0; i < p.size(); i++) if(p[i] == s.size()) match.emplace_back(i-2*s.size());
    return match;
}

//ans[i] = the number of times the prefix of size i appears in s
//ans is monothonic, therefore we can do binary seach on it
vector<int> count_pref(string &s){ //O(n)
    vector<int> p = pi(s), ans(s.size()+1); 
    for(int i = 0; i < s.size(); i++) ans[p[i]]++;
    for(int i = s.size()-1; i > 0; i--) ans[p[i-1]] += ans[i];
    for(int i = 0; i <= s.size(); i++) ans[i]++;
    return ans;
}
