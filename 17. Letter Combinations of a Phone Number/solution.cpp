class Solution {
private:
    vector<string> ans;
    string map[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string query;
    int size;
    
    void recursive(string s, int idx) {
        if (idx == size) {
            ans.push_back(s);
            return;
        }
        for (auto c: map[query[idx]-'2']) {
            recursive(s+c, idx+1);
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") {
            return ans;
        }
        query = digits;
        size = digits.size();
        recursive("", 0);
        return ans;
    }
};