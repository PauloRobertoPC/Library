#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int n, c;
vector<int> arr;
vector<vector<ld>> dp, errors;
vector<vector<bool>> seen, seenErrors;

ld erro(int i, int j){
    if(seenErrors[i][j])
        return errors[i][j];
    auto &val = errors[i][j];
    seenErrors[i][j] = 1;
    val = 0;
    for(int k=i+1;k<j;k++){
        val += abs(arr[i]+(arr[j]-arr[i])*(k-i)*(1.0/(j-i))-arr[k]);
    }
    
    return val;
}

ld solve(int i, int c){
    if(i==n)
        return 0;
    if(seen[i][c])
        return dp[i][c];
     
    auto &val = dp[i][c];
    seen[i][c] = 1;
    val = 1e17;
    if(c==1){
        val = erro(i,n-1); 
    }
    else{
        for(int k=i+1;k<n;k++){
            val = min(erro(i,k) + solve(k,c-1),val);
        }
    }
    
    return val;
}

int main(){
    int t;
    cin >> t;
    cout << fixed << setprecision(4);
    while(t--){
        cin >> n >> c;
        
        arr.assign(n,0);
        for(auto &x:arr)
            cin >> x;
        
        dp.assign(n,vector<ld>(c,0));
        seen.assign(n,vector<bool>(c,0));

        errors.assign(n,vector<ld>(n,-10));
        seenErrors.assign(n,vector<bool>(n,0));

                
        cout << solve(0,c-1)*1.0/n << "\n";
       
    }

    return 0;
}