#include<bits/stdc++.h>
using namespace std;

int SubarrayMinimum(vector<int> &arr) {
    int n = arr.size();
    int M = 1e9 + 7;
    vector<int>nse(n),pse(n);
    stack<int>st;

        //next Smaller elements
    for(int i = 0; i < n; i++) {

        while(!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    //jane se phale stack ko clear karna hai kyuki mere ko isme next greater elements ko fill karna hai
    while(!st.empty()){
        st.pop();
    }
    //next greater elements
    for(int i = n-1; i >=0; i--) {

        while(!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    // calculate answer
    long long sum = 0;

    for(int i = 0; i < n; i++) {
        long long left = i - pse[i];
        long long right = nse[i] - i;

        sum = (sum + (arr[i] * left * right) % M) % M;
    }
    return sum;

}

int main() {
    int n;
    cin>>n;

    vector<int>nums(n);

    for(int i = 0; i < n; i++) {
        cin>>nums[i];
    }

    int ans = SubarrayMinimum(nums);
    cout<<ans;
    return 0;
}