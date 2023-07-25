#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int, int, int> i5;
typedef priority_queue<i5, vector<i5>, greater<i5>> PQ;

int tot[3];
int value_note[6] = {100, 50, 20, 10, 5, 1};
int dist[2][4][1010][1010];

void dijkstra(int direction){
    int step = (direction == 0 ? 1 : -1);
    int note = (direction == 5 ? 0 : 5);
    PQ pq;
}

int main(){
    int t; cin >> t;
    while(t--){
        memset(dist, 0x3f3f3f3f, sizeof(dist));
        tot[0] = tot[1] = tot[2] = 0;
        int variation[3] = {0, 0, 0};
        int owe; cin >> owe; 
        variation[0] -= owe;
        variation[1] += owe;
        cin >> owe;
        variation[1] -= owe;
        variation[2] += owe;
        cin >> owe;
        variation[2] -= owe;
        variation[0] += owe;

        for(int person = 0, tot_notes; person < 3; person++){
            for(int note = 0; note < 6; note++){
                cin >> tot_notes;
                tot[person] += value_note[note]*tot_notes;
            }
        }

        dijkstra(0);
        for(int i = 0; i < 3; i++) tot[i] += variation[i];
        dijkstra(1);

    }
    return 0;
}
