#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

// int Operate(int a, int b, string token) {
//     if(token == "+"){
//         return a+b;
//     }
//     if(token == "-"){
//         return a-b;
//     }
//     if(token == "*"){
//         return (long)a*(long)b;
//     }
//     if(token == "/"){
//         return a/b;
//     }
//     return -1;
// }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
            // by lambda function 
        unordered_map<string,function<int (int,int)> > mp = {
            {"+",[](int a,int b){return a+b;} },
            {"-",[](int a,int b){return a-b;} },
            {"*",[](int a,int b){return (long)a*(long)b;} },
            {"/",[](int a,int b){return a/b;} },
            
        };
        
        for(string &token : tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/" ) {
                //top ke 2 elements ko pop ke uske baad usko solve karlunga 
                //then push in stack

                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                int result = mp[token](a,b);//Operate(a,b,token);

                st.push(result);
            }else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
int main() {
    int n;
    cin>>n;

    vector<string>tokens(n);

    for(int i =0; i< n; i++) {
        cin>>tokens[i];
    }
    Solution obj;

    cout<<obj.evalRPN(tokens);
    return 0;

    
}
