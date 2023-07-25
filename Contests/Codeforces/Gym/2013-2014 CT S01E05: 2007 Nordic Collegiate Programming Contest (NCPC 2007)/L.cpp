#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    map<string,string> party;
    map<string,int> votes;
cin.ignore();
    for(int i=0;i<n;i++){
        string name, p;

        
        getline(cin,name);
        getline(cin,p);
       
        party[name] = p;
    }

    int m;
    cin >> m;
 cin.ignore();
    while(m--){
        string name;
       
        getline(cin,name);
        votes[name]++;
    }

    int mx = -1;
    string answ = "";
    for(auto p:votes){
       
        if(p.second==mx){
            answ = "tie";
        }
        if(p.second>mx){
            mx = p.second;
            answ = party[p.first];
        }
    }

  

    cout << answ << "\n";

    return 0;
}