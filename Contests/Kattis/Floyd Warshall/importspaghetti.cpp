#include <bits/stdc++.h>

using namespace std;

void calcPath(vector<vector<int>> &dad, vector<int> &path, int i, int j){
    if(i != j) calcPath(dad, path, i, dad[i][j]);
    path.emplace_back(j);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> M(n, vector<int>(n, int(1e8)));
    vector<vector<int>> dad(n, vector<int>(n, int(1e8)));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            dad[i][j] = i;
    map<string, int> go;
    map<int, string> back;
    for(int i = 0; i < n; i++){
        cin >> back[i];
        go[back[i]] = i;
    }
    string ans = "";
    for(int i = 0; i < n; i++){
        string s, t; int k; cin >> s >> k;
        getline(cin, t);
        while(k--){
            getline(cin, t);
            stringstream sin(t);
            sin>>t;
            while(sin>>t){
                if(t.back() == ',') t.pop_back();
                if(s == t) ans = s;
                M[go[s]][go[t]] = 1;
            }
        }
    }
    if(ans != ""){
        cout << ans << "\n";
        return 0;
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(M[i][k] + M[k][j] < M[i][j]){
                    M[i][j] = M[i][k] + M[k][j];
                    dad[i][j] = dad[k][j];
                }
            }
        }
    }
    int mmin = 1e8, vmin;
    for(int i = 0; i < n; i++){
        if(M[i][i] < mmin){
            mmin = M[i][i];
            vmin = i;
        }
    }
    if(mmin == 1e8){
        cout << "SHIP IT\n";
        return 0;
    }
    vector<int> path;
    for(int i = 0; i < n; i++){
        if(i == vmin) continue;;
        if(M[vmin][i] == mmin-1 && M[i][vmin] == 1){
            calcPath(dad, path, vmin, i);
            break;
        }
    }
    for(int x:path) cout << back[x] << " ";
    cout << "\n";
    return 0;
}
