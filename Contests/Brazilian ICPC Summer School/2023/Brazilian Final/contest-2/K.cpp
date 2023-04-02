#include <bits/stdc++.h>

using namespace std;

int n, m;
int correct[36];
string num[36];

int backtrack(int pos, vector<int> v){
    if(pos == n){
        bool ok = true;
        for(int i = 0; i < m; i++) ok &= (v[i] == correct[i]);
        return ok;
    }
    int ans = 0;
    for(int bit = 0; bit <= 1; bit++){
        vector<int> v2 = v;
        bool prone = false;
        for(int i = 0; i < m; i++){
            v2[i] += (num[i][pos]==char(bit+'0'));
            prone |= (v2[i] > correct[i]);
        }
        if(!prone)
            ans += backtrack(pos+1, v2);
    }
    return ans;
}

int main(){
    cin >> n >> m; 
    for(int j = 0; j < m; j++)
        cin >> num[j] >> correct[j]; 
    cout << backtrack(0, vector<int>(m, 0)) << "\n";
    return 0;
}
// Description: Backtrack
