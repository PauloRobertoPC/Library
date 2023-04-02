#include <bits/stdc++.h>

using namespace std;

int n;

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        bool ok = true;
        vector<int> ans;
        if(n == 1){
            ans.emplace_back(1);
        }else if(n == 2 || n == 3){
            ok = false;
        }else{
            for(int i = n; i >= 1; i -= 4){
                if(i >= 4){
                    vector<int> use;
                    for(int j = 0; i-j >= 1 && j < 4; j++) use.emplace_back(i-j);
                    ans.emplace_back(use[1]);
                    ans.emplace_back(use[3]);
                    ans.emplace_back(use[0]);
                    ans.emplace_back(use[2]);
                }else if(i == 1){
                    ans.emplace_back(1);
                }else if(i == 2){
                    ans.pop_back();     
                    ans.emplace_back(2);
                    ans.emplace_back(4);
                    ans.emplace_back(1);
                }else if(i == 3){
                    ans.pop_back();     
                    ans.emplace_back(3);
                    ans.emplace_back(1);
                    ans.emplace_back(5);
                    ans.emplace_back(2);
                }else{
                    ok = false;
                }
            }
        }
        if(ok){
            for(int i = 0; i < n; i++) cout << ans[i] << " "; cout << "\n";
        }else{
            cout << "-1\n";
        }
    }
    return 0;
}
