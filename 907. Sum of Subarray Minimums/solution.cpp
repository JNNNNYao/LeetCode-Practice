class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = (int)pow(10,9)+7;
        stack<int> st;  // store the min of some subarray, running backward
        stack<int> num; // indicate how many subarray the min in st correspond to
                        // think of st and num as two identical stack with different information
        int ans = arr[0];
        int prev = arr[0];
        st.push(arr[0]);
        num.push(1);
        for(int i = 1; i < arr.size(); i++){
            int diff = 0;
            int cnt = 0;
            while(!st.empty() && arr[i] <= st.top()){
                diff += num.top() * (st.top() - arr[i]);
                cnt += num.top();
                st.pop();
                num.pop();
            }
            
            ans = (ans + prev - diff + arr[i]) % mod;
            prev = (prev - diff + arr[i]) % mod;
            st.push(arr[i]);
            num.push(1 + cnt);
        }
        return ans % mod;
    }
};