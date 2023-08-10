#include <bits/stdc++.h>

using namespace std;

void hanoi(int disks, int to, int trash, int from){
    if(disks == 0) return;
    hanoi(disks-1, to, from, trash);
    cout << to << " " << from << "\n";
    hanoi(disks-1, trash, to, from);
}

int main(){
    int n; cin >> n;
    cout << (1<<n)-1 << "\n";
    hanoi(n, 1, 2, 3);
    return 0;
}
