#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s, int l, int r){
    while(l < r){
        if(s[l] != s[r]) return false;
        ++l; --r;
    }
    return true;
}

int main(){
    string s; cin >> s;
    bool ok = false, entrou = false;
    int l = 0, r = s.size()-1, rm;
    while(l < r){
        if(s[l] != s[r]){
            entrou = true; 
            if(isPalindrome(s, l+1, r)){
                ok = true;
                rm = l;
            }
            if(isPalindrome(s, l, r-1)){
                ok = true;
                rm = r;
            }
            break;
        }
        ++l; --r;
    }
    if(!entrou && isPalindrome(s.substr(0, s.size()/2)+s.substr(s.size()/2+1), 0, s.size()-2)){
        ok = true;
        rm = s.size()/2;
    }
    if(ok){
        cout << "YES\n";
        cout << rm+1 << "\n";
    }else{
        cout << "NO\n";
    }
}
// Description: String - Check if is Palindrome when a character is removed
