#include <bits/stdc++.h>

using namespace std;

vector<deque<pair<char, char>>> dq;

void jogada(int &pos, int &dir){
    
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<char, char>> cartas(m);
    dq.resize(n);
    for(auto &[x, y]:cartas) cin >> x >> y;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 7; j++){
            char num; char ch;
            cin >> num >> ch;
            dq[i].push_back({num, ch});
        }
    }
    char num, cor; tie(num, cor) = dq[0].front(); dq[0].pop_front();
    int pos, dir;
    if(num == 'R'){
        pos = n-1;
        dir = -1;
    }else if(num == 'B'){
        pos = (pos+2)%n;
        dir = 1;
    }else if(num == '+'){
           
        pos = (pos+2)%n;
        dir = 1;
    }else{

    }
    while(true){
        
        pos = (pos+dir+n)%n;
    }
    return 0;
}
