#include <bits/stdc++.h>

using namespace std;

int main(){
    cout << fixed << setprecision(10);
    long long n, x;
    cin >> n >> x;
    vector<long long> v(n);
    double sum1 = 0, sum2 = n*x;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sum1 += v[i]*v[i];
    }
    if(sum1 == 0){
        for(int i = 0; i < n; i++) cout << "0 "; cout << "\n";
        return 0;
    }
    double f = sqrt(n*x/sum1);
    for(int i = 0; i < n; i++)
        cout << v[i]*f << " "; 
    cout << "\n";
    return 0;
}
