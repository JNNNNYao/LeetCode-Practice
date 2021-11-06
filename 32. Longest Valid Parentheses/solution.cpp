class Solution {
public:
    int longestValidParentheses(string s) {
        int match_left[s.size()];   // the index of the matched left parentheses
        stack<int> st;    // the unmatched left parentheses
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(') {
                st.push(i);
                match_left[i] = -1;
            }
            else {
                if (st.size() == 0) {
                    match_left[i] = -1;
                }
                else {
                    match_left[i] = st.top();
                    st.pop();
                }
            }
        }
        int ans = 0;
        int curr = 0;   // the current longese valid parentheses
        for (int i = s.size()-1; i >= 0; ) {
            if (match_left[i] != -1) {
                curr += (i-match_left[i]+1);
                i = match_left[i]-1;
                if (curr > ans) {
                    ans = curr;
                }
            }
            else {
                curr = 0;
                i--;
            }
        }
        return ans;
    }
};