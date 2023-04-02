#include <bits/stdc++.h>
#include <string>

using namespace std;

int main(){
    string s; 
    cin >> s;
    bool imp = false;
    int sum = 0;
    for(auto ch:s){
        sum += (ch == '(');
        sum -= (ch == ')');
        if(sum < 0) imp = true;
    }
    if(imp){
        cout << "IMPOSSIBLE\n";
    }else{
        s += string(sum, ')');
        cout << s << "\n";
    }
    return 0;
}
