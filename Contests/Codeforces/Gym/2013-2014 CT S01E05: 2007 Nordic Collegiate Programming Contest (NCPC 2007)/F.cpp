#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
vector<int> cost;
vector<vector<pair<int,int>>> adj;
const ll inf = 1e17;

int best(int s, int c, int f){
    vector<vector<ll>> dist(n+1,vector<ll>(c+1,inf));
    priority_queue<tuple<ll,int,int>> pq;

    dist[s][0] = 0;
    pq.push({-dist[s][0],s,0});
    
    ll d;
    int u, cap;
    while(pq.size()){
        tie(d,u,cap) = pq.top(), pq.pop(), d = -d;
        //cout << d <<" " << s << " " << cap << "\n";         
        if(u==f)
            return d;
        if(d>dist[u][cap]) continue;

        if(cap+1<=c && d+cost[u] < dist[u][cap+1]){
            dist[u][cap+1] = cost[u]+d;
            pq.push({-dist[u][cap+1],u,cap+1}); 
        }

        for(auto [v,wt] : adj[u]){
            if(cap>=wt && d < dist[v][cap-wt]){
                dist[v][cap-wt] = d;
                pq.push({-dist[v][cap-wt],v,cap-wt});
            }
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;
    cost.assign(n+1,0);
    for(int i=0;i<n;i++){ 
        cin >> cost[i];
    }

    adj.assign(n+1,vector<pair<int,int>>());
    for(int i=0;i<m;i++){
        int a, b, d;
        cin >> a >> b >> d;
        adj[a].push_back({b,d});
        adj[b].push_back({a,d});
    }

    int q;
    cin >> q;
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        ll answ = best(b,a,c);

        if(answ==-1){
            cout << "impossible" << "\n";
        }
        else{
            cout << answ << "\n";
        }
    }   

    return 0;
}