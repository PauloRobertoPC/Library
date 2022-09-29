#include <bits/stdc++.h>

using namespace std;

struct vp{
    int x, y;

    vp(int x, int y) : x(x), y(y){}

    vp operator-(vp b){ return vp(x-b.x, y-b.y); }
    int operator*(vp b){ return x*b.x + y*b.y; }
    int operator%(vp b){ return x*b.y - y*b.x; }
    int operator~(){ return x*x + y*y; }
    bool operator==(vp b){ return x == b.x && y == b.y; }
};

bool horario(vp a, vp b, vp c){
    vp ab = b-a, ac = c-a;
    return ((ab%ac) > 0);
}

bool cruza(vp a, vp b, vp c, vp d){
    return ((horario(a, b, c) != horario(a, b, d)) && (horario(c, d, a) != horario(c, d, b)));
}

int main(){
    vector<vp> v;
    for(int i = 0; i < 7; i++){
        int x, y;
        cin >> x >> y;
        v.push_back(vp(x, y));
    }
    bool ok = true; 
    ok &= ((v[1]-v[0])*(v[2]-v[0]) > 0);            //1
    
    ok &= (~(v[1]-v[0]) == ~(v[2]-v[0]));           //2

    ok &= ((v[2]-v[1])%(v[3]-v[1]) == 0);           //3
    ok &= ((v[2]-v[1])%(v[4]-v[1]) == 0);           //3
    
    ok &= (vp((v[2].x+v[1].x), (v[2].y+v[1].y)) == vp((v[4].x+v[3].x), (v[4].y+v[3].y)));           //4

    ok &= (~(v[2]-v[1]) > ~(v[4]-v[3]));            //5
    
    ok &= ((v[5]-v[3])*(v[2]-v[1]) == 0);           //6
    ok &= ((v[6]-v[4])*(v[2]-v[1]) == 0);           //6

    ok &= (~(v[5]-v[3]) == ~(v[6]-v[4]));           //7

    ok &= cruza(v[0], v[5], v[1], v[2]);
    
    cout << (ok ? "S" : "N") << "\n";
    
    return 0;
}
