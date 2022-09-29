#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> custo_coluna(m, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int num; cin >> num;
            custo_coluna[j] += num;
        }
    }
    cout << *(min_element(custo_coluna.begin(), custo_coluna.end())) << "\n";
    return 0;
}
