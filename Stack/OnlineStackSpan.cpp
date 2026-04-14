#include<bits/stdc++.h>
using namespace std;

class Stackspanner {
    public:
    stack<pair<int,int>>st;
    int ind;
    Stackspanner() {
        ind = -1;
    }

    int next(int price) {
        ind = ind + 1;

        while(!st.empty() && st.top().first <= price) {
            st.pop();
        }
        int ans = ind - (st.empty() ? -1 : st.top().second);
        st.push({price,ind});
        return ans;
    }
};

int main() {
    int n;
    cin>>n;

    Stackspanner obj;

    for(int i = 0; i < n; i++) {
        int price;
        cin>>price;
        cout<<obj.next(price)<< " ";
    }
    return 0;

}