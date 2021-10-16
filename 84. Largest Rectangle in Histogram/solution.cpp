class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = heights[0];
        int min, val;
        int num[10001]={0};
        vector<int> st;
        st.push_back(heights[0]);
        for(int i = 1; i < heights.size(); i++){
            min = i;
            while(!st.empty() && heights[i] < st.back()){
                val = st.back();
                if(ans < val * (i-num[val])){
                    ans = val * (i-num[val]);
                }
                if(num[val] < min){
                    min = num[val];
                }
                num[val] = 0;
                st.pop_back();
            }
            if(st.empty() || st.back() != heights[i]){
                num[heights[i]] = min;
                st.push_back(heights[i]);   
            }
        }
        for(auto iter: st){
            if(ans < iter * (heights.size()-num[iter])){
                ans = iter * (heights.size()-num[iter]);
            }
        }
        return ans;
    }
};



class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = heights[0];
        int max;
        int num[10001]={0};
        num[heights[0]]++;
        vector<int> st;
        st.push_back(heights[0]);
        for(int i = 1; i < heights.size(); i++){
            max = 0;
            while(!st.empty() && heights[i] <= st.back()){
                if(num[st.back()] > max){
                    max = num[st.back()];
                }
                num[st.back()] = 0;
                st.pop_back();
            }
            num[heights[i]] = max;
            st.push_back(heights[i]);
            for(auto iter: st){
                num[iter]++;
                if(iter * num[iter] > ans){
                    ans = iter * num[iter];
                }
            }
        }
        return ans;
    }
};