class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        stack<int> st;  // this is an descending stack
        int NGN[10001];
        st.push(nums2[n2-1]);
        NGN[nums2[n2-1]] = -1;
        for(int i = n2-2; i >= 0; i--){
            while(!st.empty() && nums2[i] >= st.top()){
                st.pop();
            }
            if(st.empty()){
                NGN[nums2[i]] = -1;
            }
            else{
                NGN[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        for(int i = 0; i < n1; i++){
            nums1[i] = NGN[nums1[i]];
        }
        return nums1;
    }
};