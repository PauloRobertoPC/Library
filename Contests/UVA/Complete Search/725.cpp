#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, c = 0;
    while(cin >> n, n){
        int tot = 0;
        if(c++) cout << "\n";
        for(int i = 1234; i <= 98765; i++){
            int j = n*i;
            string s1 = to_string(j), s2 = to_string(i);
            if(s1.size() > 5) continue;
            s1 = string(5-s1.size(), '0')+s1;
            s2 = string(5-s2.size(), '0')+s2;
            int used = 0;
            for(int i = 0; i < 5; i++){
                used |= (1<<(int(s1[i]-'0')));
                used |= (1<<(int(s2[i]-'0')));
            }
            if(used == (1<<10)-1)
                cout << s1 << " / " << s2 << " = " << n << "\n",
                ++tot;
        }
        if(!tot)
            cout << "There are no solutions for " << n << ".\n";
    }
    return 0;
}
