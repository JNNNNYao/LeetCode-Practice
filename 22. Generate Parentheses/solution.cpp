class Solution {
private:
    vector<string> ans;
    void recursive(int left, int right, string s) {
        if (left == 0 && right == 0) {
            ans.push_back(s);
            return;
        }
        
        if (left > 0)
            recursive(left-1, right, s+"(");
        if (left < right)   // if we have not matched left
            recursive(left, right-1, s+")");
    }
public:
    vector<string> generateParenthesis(int n) {
        recursive(n, n, "");
        return ans;
    }
};