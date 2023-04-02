#include <bits/stdc++.h>

using namespace std;

int mod;

struct Matrix{
    vector<vector<int>> M; 

    Matrix(int n){
        M.assign(n, vector<int>(n, 0));
    }

    Matrix operator*(Matrix o){
        int n = M.size();
        Matrix ans(n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++)
                   ans.M[i][j] = (ans.M[i][j] + (this->M[i][k]*o.M[k][j])%mod)%mod;
        return ans;
    }

    Matrix operator^(int e){
        int n = M.size();
        Matrix ans(n), b(n);
        b.M = this->M;
        for(int i = 0; i < n; i++) ans.M[i][i] = 1;
        while(e){
            if(e&1) ans = ans*b;
            e >>= 1;
            b = b*b;
        }
        return ans;
    }
};

int main(){
    int t; cin >> t;
    int c = 1;
    while(t--){
        cout << "Case " << c++ << ":\n";
        int a1, b1, c1; cin >> a1 >> b1 >> c1;
        int a2, b2, c2; cin >> a2 >> b2 >> c2;
        Matrix M(6);
        M.M = {
                {a1, b1, 0, 0, 0, c1},
                {1, 0, 0, 0, 0, 0},
                {0, 1, 0, 0, 0, 0},
                {0, 0, c2, a2, b2, 0},
                {0, 0, 0, 1, 0, 0},
                {0, 0, 0, 0, 1, 0},
              };
        vector<int> fun(6);
        for(int &x:fun) cin >> x;
        cin >> mod;
        for(int &x:fun) x %= mod;
        swap(fun[0], fun[2]);
        swap(fun[3], fun[5]);
        int q; cin >> q;
        while(q--){
            int n; cin >> n;
            if(n == 0){
                cout << fun[2] << " " << fun[5] << "\n";
            }else if(n == 1){
                cout << fun[1] << " " << fun[4] << "\n";
            }else if(n == 2){
                cout << fun[0] << " " << fun[3] << "\n";
            }else{
                Matrix e = M^(n-2); 
                int f = 0, g = 0;
                for(int i = 0; i < 6; i++){
                    f = (f + (fun[i]*e.M[0][i])%mod)%mod;
                    g = (g + (fun[i]*e.M[3][i])%mod)%mod;
                }
                cout << f << " " << g << "\n";
            }
        }
    }
    return 0;
}
// Description: Math - Linear Recurrence
