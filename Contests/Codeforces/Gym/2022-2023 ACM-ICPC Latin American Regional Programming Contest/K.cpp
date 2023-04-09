#include <bits/stdc++.h>

using namespace std;

int k;
int M[110][110];

int main(){
    cin >> k;
    int pot = 0;
    while((1<<pot) < k) ++pot;
    int mask = (1<<pot)-1;
    for(int j = 1; j <= 100; j++){
        M[1][j] = mask;
        if(j&1)
            for(int i = 1; i <= 100; i++)
                M[i][j] = mask;
    }
    k -= 2;
    int c = 1;
    for(int i = 1; i <= 100 && k; i++)
        for(int j = 1; j <= 100 && k; j++)
            if(!M[i][j]){
                M[i][j] = c++;
                --k;
            }
    map<int, vector<pair<int, int>>> mp;
    for(int i = 1; i <= 100; i++)
        for(int j = 1; j <= 100; j++)
            for(int k = 0; (mask&(1<<k)); k++)
                if(M[i][j]&(1<<k))
                    mp[k].emplace_back(i, j);

    cout << mp.size() << "\n";
    for(auto par:mp){
        cout << par.second.size() << " ";
        for(auto [i, j]:par.second)
            cout << i << " " << j << " ";
        cout << "\n";
    }

    return 0;
}
