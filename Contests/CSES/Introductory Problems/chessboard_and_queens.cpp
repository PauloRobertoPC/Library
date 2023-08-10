#include <bits/stdc++.h>

using namespace std;

int ans;
int col[8];
vector<string> M(8);

bool ok(int row){
    vector<bitset<8>> used(8);
    for(int i = 0; i < row; i++){
        for(int x = i, y = col[i]; x < 8 && y < 8; x++, y++)
            if(used[x][y]) return false;
        for(int x = i-1, y = col[i]-1; x >= 0 && y >= 0; x--, y--)
            if(used[x][y]) return false;
        for(int x = i-1, y = col[i]+1; x >= 0 && y < 8; x--, y++)
            if(used[x][y]) return false;
        for(int x = i+1, y = col[i]-1; x < 8 && y >= 0; x++, y--)
            if(used[x][y]) return false;
        used[i][col[i]] = 1;
    }
    return true;
}


void backtrack(int row = 0, int mask = 0){
    if(row == 8){
        ans += ok(row);
        return;
    }
    for(int j = 0; j < 8; j++){
        if(M[row][j] == '.' && (mask&(1<<j)) == 0 && ok(row)){
            col[row] = j;
            backtrack(row+1, mask|(1<<j));
        }
    }

}

int main(){
    for(string &s:M) cin >> s;
    backtrack();
    cout << ans << "\n";
    return 0;
}
