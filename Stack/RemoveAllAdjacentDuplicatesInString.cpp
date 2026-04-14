#include<bits/stdc++.h>
using namespace std;

string removedublicate(string s) {
    string result = "";
    for(char ch: s) {
        if(!result.empty() && result.back() == ch){
            result.pop_back();
        } else{
            result.push_back(ch);
        }
    }
    return result;
}

int main() {
    string s;
    cin>>s;

    string ans = removedublicate(s);
    for(char ch:ans){
        cout<<ch;
    } 
    return 0;

}