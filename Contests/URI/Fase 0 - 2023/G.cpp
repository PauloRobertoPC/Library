#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool isChar(char c){
    return ((c>='a' && c<='z') || (c>='A' && c<='Z'));
}

bool isSeparator(char c){
    return (c==' ' || c=='.' || c==',');
}

bool isDigit(char c){
    return (c>='0' && c<='9');
}

vector<string> split(string s){
    vector<string> answ;
    string acm = "";

    for(auto c:s){
        if(isSeparator(c)){
            answ.push_back(acm);
            acm = "";
        }
        else{
            if(acm=="")
                answ.push_back("");
            acm.push_back(c);
        }
    }
    answ.push_back(acm);
    return answ;
}

bool isNumber(string s){
    for(auto c:s){
        if(!isDigit(c)){
            return false;
        }
    }
    return true;
}

string format(string s){
    if(s.size()==0) return s;
    reverse(s.begin(),s.end());
    while(s.size() && s.back()=='0')
        s.pop_back();
    if(s.size()==0)
        s = "0";
    reverse(s.begin(),s.end());
    return s;
}

string sum1(string x){
    int carry = 1;
    reverse(x.begin(),x.end());
    for(int i=0;i<x.size();i++){
        int valor = carry+x[i]-'0';
        if(valor<=9){
            x[i] = '0'+valor;
            carry = 0;
            break;
        }
        else{
            x[i] = '0'+valor%10;
            carry = valor/10;
        }
    }
    if(carry){
        x.push_back('0'+carry);
    }
    reverse(x.begin(),x.end());
    return x;
}

bool check(vector<string> s){
    vector<int> num;
    for(auto ss:s)
    num.push_back(stoll(ss));

    set<ll> st, hasNext;
    for(int i=num.size()-1;i>=0;i--){
        if(st.find(num[i]+1)!=st.end()){
            hasNext.insert(num[i]);
        }
        if(hasNext.find(num[i]+1)!=hasNext.end()){
            return true;
        }
        st.insert(num[i]);
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    vector<string> numbers;

    for(int i=0;i<n;i++){
        string s;
        getline(cin,s);

        auto v = split(s);

        string numberAcm = "";
        for(int i=0;i<v.size();i++){
            if(v[i]==""){
                if(i>0 && v[i-1]==""){
                    if(numberAcm.size()!=0)
                        numbers.push_back(format(numberAcm));
                    numberAcm = "";
                }
            }
            else if(isNumber(v[i])){
                numberAcm += v[i];
            }
            else{
                if(i>0 && v[i-1]==""){
                    if(numberAcm.size()!=0)
                        numbers.push_back(format(numberAcm));
                    numberAcm = "";
                }
            }
        }
        //cout <<"\n";
        if(numberAcm.size()!=0)
            numbers.push_back(format(numberAcm));
        numberAcm = "";

    }


    for(auto x:numbers){
        cout << x << " ";
    }
    cout<<"\n";

    bool ok = check(numbers);
    if(ok){
        cout << "123" <<"\n";
    }
    else{
        cout << ":)" <<"\n";
    }

    return 0;
}
