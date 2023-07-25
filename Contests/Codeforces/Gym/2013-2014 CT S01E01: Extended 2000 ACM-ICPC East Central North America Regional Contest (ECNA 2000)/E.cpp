#include <bits/stdc++.h>

using namespace std;

#define RED 0
#define WHITE 1
#define INF int(1e9)

vector<int> read_walk(){
    vector<int> walk;
    char ch; string s; int t; cin >> s;
    stringstream sin(s);
    int cnt = count(s.begin(), s.end(), '-');
    while(cnt != -1){
        sin >> t; walk.emplace_back(t);
        if(cnt) sin >> ch;
        --cnt;
    }
    return walk;
}

vector<pair<int, int>> p; //p[position] = {color, is_king}
pair<int, int> walk_red[2] = {{+1, -1}, {+1, +1}};
pair<int, int> walk_white[2] = {{-1, -1}, {-1, +1}};
vector<tuple<int, int>> adj1[40]; // {adj, color_can}
vector<tuple<int, int, int>> adj2[40]; // {adj, color_can, eat_pos}
int turn_king[40]; //if turn_king[pos] = COLOR, then COLOR become KING

bool in(int i, int j){
    return i >= 0 && i < 8 && j >= 0 && j < 8;
}

void init(){
    int M[8][8];
    for(int i = 0, cnt = 1; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if((i&1) != (j&1)) M[i][j] = cnt++;
            else M[i][j] = 0;
        }
    }
    for(int i = 0, cnt = 1; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(!M[i][j]) continue;
            for(int k = 0; k < 2; k++){
                //RED MOVEMENTS
                int ni1 = i+walk_red[k].first, nj1 = j+walk_red[k].second;
                int ni2 = i+2*walk_red[k].first, nj2 = j+2*walk_red[k].second;
                if(in(ni1, nj1)) adj1[M[i][j]].emplace_back(M[ni1][nj1], RED);
                if(in(ni2, nj2)) adj2[M[i][j]].emplace_back(M[ni2][nj2], RED, M[ni1][nj1]);
                //WHITE MOVEMENTS
                ni1 = i+walk_white[k].first, nj1 = j+walk_white[k].second;
                ni2 = i+2*walk_white[k].first, nj2 = j+2*walk_white[k].second;
                if(in(ni1, nj1)) adj1[M[i][j]].emplace_back(M[ni1][nj1], WHITE);
                if(in(ni2, nj2)) adj2[M[i][j]].emplace_back(M[ni2][nj2], WHITE, M[ni1][nj1]);
            }
        }
    }
    memset(turn_king, -1, sizeof(turn_king));
    turn_king[1] = turn_king[2] = turn_king[3] = turn_king[4] = WHITE;
    turn_king[29] = turn_king[30] = turn_king[31] = turn_king[32] = RED;
}

int can_do1(int a, int b){
    if(a < 1 || a > 32 || p[a].first == -1) return -1; //NO ONE IS IN 'a'
    if(b < 1 || b > 32 || p[b].first != -1) return -1; //SOMEONE IS IN 'b'
    int i = 0;
    for(auto [v, color]:adj1[a]){
        //'v' is where we wanna go and (we can do the movement or we are king)
        if(v == b && (color == p[a].first || p[a].second == 1))
            return i;
        ++i;
    }
    return -1;
}

int can_do2(int a, int b){
    if(a < 1 || a > 32 || p[a].first == -1) return -1; //NO ONE IS IN 'a'
    if(b < 1 || b > 32 || p[b].first != -1) return -1; //SOMEONE IS IN 'b'
    int i = 0; 
    for(auto [v, color, eat]:adj2[a]){
        //'v' is where we wanna go and (we can do the movement or we are king)
        if(v == b && (color == p[a].first || p[a].second == 1)){
            if(p[eat].first == -1) return -1; //NO ONE IS IN 'eat'
            if(p[eat].first == p[a].first) return -1; // 'a' eats 'eat' and they have the same color
            return i;
        }
        ++i;
    }
    return -1;
}

bool can_eat_pos(int a){
    for(auto [b, color, eat]:adj2[a])
        if(can_do2(a, b) != -1)
            return true;
    return false;
}

bool can_eat(int color){
    for(int a = 1; a <= 32; a++){
        if(p[a].first != color) continue;
        for(auto [b, color, eat]:adj2[a])
            if(can_do2(a, b) != -1)
                return true;
    }
    return false;
}

bool is_movement1(int a, int b){
    for(auto [v, color]:adj1[a])
        if(v == b) return true;
    return false;
}

bool do_movement1(vector<int> &walk, int color){
    int a = walk[0], b = walk[1];
    if(a < 1 || a > 32 || p[a].first != color) return false;
    if(can_do1(a, b) != -1){
        swap(p[a], p[b]);
        p[b].second |= (turn_king[b] == color);
        return true;
    }
    return false;
}

bool do_movement2(int a, int b, int color){
    int i = can_do2(a, b);
    if(i != -1){
        int aux1, aux2, eat; tie(aux1, aux2, eat) = adj2[a][i];
        p[eat] = {-1, -1};
        swap(p[a], p[b]);
        p[b].second |= (turn_king[b] == color);
        return true;
    }
    return false;
}

bool do_movements2(vector<int> &walk, int color){
    int a = walk[0], b; bool became_king = false;
    if(a < 1 || a > 32 || p[a].first != color) return false;
    for(int i = 1; i < walk.size(); i++){
        if(became_king) return false; //Once a piece is promoted, its move ends
        a = walk[i-1]; b = walk[i];
        int is_king_before = p[a].second;
        if(!do_movement2(a, b, color)) return false;
        int is_king_after = p[b].second;
        became_king |= (!is_king_before && is_king_after);
    }
    //the piece did not become king and it can eat someone else, then it must
    if(!became_king && can_eat_pos(b)) return false;
    return true;
}

int main(){
    init();
    int r, w;
    while(cin >> r >> w){
        if(!r && !w) break;
        p.assign(40, {-1, -1});
        while(r--){
            int num; cin >> num;
            p[abs(num)] = {RED, num<0};
        }
        while(w--){
            int num; cin >> num;
            p[abs(num)] = {WHITE, num<0};
        }
        int m, op; char ch;
        cin >> m >> ch;
        op = (ch == 'W');
        int pos_ans = INF;
        for(int k = 1; k <= m; k++){
            vector<int> walk = read_walk();
            //We must do at least 1 step
            if(walk.size() <= 1) 
                pos_ans = min(pos_ans, k);
            //if we are not eating the oponent we must walk just 1 step
            bool mov1 = is_movement1(walk[0], walk[1]);
            if(mov1 && walk.size() != 2) 
                pos_ans = min(pos_ans, k);
            //if can_eat then it must do it
            bool must_eat = can_eat(op);
            if(must_eat && mov1) pos_ans = min(pos_ans, k);
            //if cant do the movement then stop
            bool movement_sucessful;
            if(mov1) movement_sucessful = do_movement1(walk, op);
            else movement_sucessful = do_movements2(walk, op);
            if(!movement_sucessful) pos_ans = min(pos_ans, k);

            op ^= 1;
        }
        if(pos_ans == INF) cout << "All moves valid\n";
        else cout << "Move " << pos_ans << " is invalid\n";
    }
    return 0;
}
