#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    stack<char> st;
    getline(cin, s);
    while(getline(cin, s)){
        for(char ch:s){
            if(ch == '{'){
                st.push('{');
            }else if(ch == '}'){
                if(!st.empty() && st.top() == '{'){
                    st.pop();
                }else{
                    st.push('}');
                }
            }
        }
    }
    cout << (st.empty() ? 'S' : 'N') << "\n";
    return 0;
}
