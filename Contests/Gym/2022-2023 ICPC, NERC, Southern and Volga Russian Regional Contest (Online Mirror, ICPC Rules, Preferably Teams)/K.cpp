#include <bits/stdc++.h>

using namespace std;

#define maxn 210

long long M[maxn][maxn];

int main(){
    int n;
    cin >> n;
    long long sum = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> M[i][j],
            sum += M[i][j];
    long long mmin = 2e9;
    for(int i = n, j = 1; j <= n; j++, i--) mmin = min(mmin, M[i][j]);
    cout << sum-mmin << "\n";
    return 0;
}
