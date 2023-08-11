#include <bits/stdc++.h>

using namespace std;

#define maxn int(2e5+10)

int v[maxn], ans[maxn];

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> v[i];

    stack<pair<int, int>> st;
    for(int i = n; i >= 0; i--){
        while(!st.empty() && v[i] < st.top().first){
            ans[st.top().second] = i;
            st.pop();
        }
        st.push({v[i], i});
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << "\n";
    return 0;
}
