#include <bits/stdc++.h>

using namespace std;

#define SQRT 320
#define maxn int(1e5+10)

string s;
int n, clk;
pair<int, char> v[maxn];
pair<int, char> blocks[SQRT][SQRT][SQRT];

void update(int i, int a, int k, char ch){
    ++clk;
    int last = i+a*k;
    if(a >= SQRT){
        for(; i <= last; i+=a) v[i] = {clk, ch};
    }else{
        int b1 = i/SQRT, b2 = last/SQRT;
        int j = i;
        //Updating the beginning of block b1
        for(; j < (b1+1)*SQRT && j <= last; j += a) v[j] = {clk, ch};
        //Updating the first position of each block between the blocks [b1+1, b2-1] 
        for(int b = b1+1; b < b2; b++){
            blocks[b][i%a][a] = {clk, ch};  //every position with the same remainder i%a in the block 'b' may give this jump
            int end_b = (b+1)*SQRT-1;       //end of the current block
            int gap = end_b-j;              //gap between the j and the end_b
            int go_next = (gap/a+1);        //How much steps of size 'a' we need to go to the next block
            j += go_next*a;                 //make j point to the first position of the next block
        }
        //Updating the end of block b2
        for(; j <= last; j += a) v[j] = {clk, ch};
    }
}

char get(int i){
    char ch = v[i].second;
    int ch_clk = v[i].first;
    int b = i/SQRT;
    for(int a = 1; a < SQRT; a++){
        int i_block = i%a;
        if(blocks[b][i_block][a].first > ch_clk){
            ch_clk = blocks[b][i_block][a].first; 
            ch = blocks[b][i_block][a].second; 
        }
    }
    return ch;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s; n = s.size();
    for(int i = 0; i < n; i++) v[i] = {0, s[i]};
    int q; cin >> q;
    while(q--){
        int i, a, k; char ch; cin >> i >> a >> k >> ch; --i;
        update(i, a, k, ch);
    }
    for(int i = 0; i < n; i++) cout << get(i); cout << "\n";
    return 0;
}
// Description: Data Structures - SQRT Decomposition - Good Problem
