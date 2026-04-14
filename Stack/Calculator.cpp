#include<bits/stdc++.h>
using namespace std;

int calculator(string s) {
    int n = s.size();
        stack<int>st;
        long long number = 0 , result = 0, sign = 1;

        for(int i = 0; i < n; i++) {
    
            if(isdigit(s[i])){
                number = number*10 + (s[i] - '0');//number banate chalo 
            } else if(s[i] == '+') {// number ban chuka hai isko result mai insert karna hai 
                result += (number*sign);
                number = 0;
                sign = 1;
            }  else if(s[i] == '-') {// number ban chuka hai isko result mai insert karna hai 
                result +=(number*sign);
                number = 0;
                sign = -1;
            } else if(s[i] == '('){
                st.push(result);
                st.push(sign);
                result = 0;
                number = 0;
                sign = 1;
            } else if(s[i] == ')'){// bracket ke andar ka result hai ye 
                result += (number*sign);
                number = 0;

                int stack_sign = st.top();st.pop();
                int last_result = st.top();st.pop();

                result *=stack_sign;
                result +=last_result;
            }
        }
        result += (number*sign);
        return result;
}

int main() {
    string s;
    getline(cin,s); 

    long long ans = calculator(s);
    cout<<ans <<endl;
    return 0;

}