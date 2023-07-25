#include <bits/stdc++.h>

using namespace std;

int main(){
    long long sum = 0;
    for(int i = 1; i <= 300; i++){
        for(int j = 1; j <= 300; j++){
            sum += (300-i+1)*(300-j+1);
        }
    }
    cout << sum << "\n";
    return 0;
}
