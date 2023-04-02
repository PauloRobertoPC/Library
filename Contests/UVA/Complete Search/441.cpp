#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, c = 0;
    while(cin >> n, n){
        if(c++) cout << "\n";
        vector<int> v(n);
        for(int &x:v) cin >> x;
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                for(int k = j+1; k < n; k++)
                    for(int l = k+1; l < n; l++)
                        for(int m = l+1; m < n; m++)
                            for(int o = m+1; o < n; o++)
                                cout << v[i] << " " << v[j] << " " << v[k] << " " << v[l] << " " << v[m] << " " << v[o] << "\n";
    }
    return 0;
}
