#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

struct sede{
    string s;
    int pt, pu, rt, ru, f;
    ld score;

    sede(){}
    sede(string s1, int pt1, int pu1, int rt1, int ru1, int f1){
        s = s1;
        pt = pt1;
        pu = pu1;
        rt = rt1;
        ru = ru1;
        f = f1;
        score = 0.56*ru + 0.24*rt + 0.14*pu + 0.06*pt + 0.3*f ;
    }

    bool operator<(const sede b){
        return this->score < b.score;
    }

};

int main(){
    int n; cin >> n; 
    int pos = 0;
    vector<sede> v(6);
    for(int i = 0; i < 6; i++){
        string s;
        int pt, pu, rt, ru, f;
        cin >> s >> pt >> pu >> rt >> ru >> f;
        v[i] = sede(s, pt, pu, rt, ru, f);
    }
    sort(v.rbegin(), v.rend());
    for(int i = 0; i < 6; i++)
        if(v[i].s == "Taiwan") pos = i;
    int todo = n/6;
    int resto = n - 6*todo;

    // cout << todo << " " << resto << " " << pos << "\n";
    cout << todo + (pos < resto) << "\n";

    return 0;
}
