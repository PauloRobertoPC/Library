#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n,0);
        for(auto &x:arr)
            cin >> x;

        sort(arr.rbegin(),arr.rend());

        ll answ = 0;
        for(int i=2;i<n;i+=3){
            answ += arr[i];
        }

        cout << answ << "\n";
    }

    return 0;
}