class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        int l = num.length();
        for(int i = 0; i < l; i++){
            while(!ans.empty() && k > 0 && num[i] < ans.back()){
                ans.pop_back();
                k--;
            }
            ans.push_back(num[i]);
        }
        if(k > 0){
            while(!ans.empty() && k > 0){
                ans.pop_back();
                k--;
            }
            if(ans.empty()){
                return "0";
            }
        }
        if(ans[0] == '0'){
            while(ans[0] == '0' && ans.length() > 1){
                ans.erase(0, 1);
            }
        }
        return ans;
    }
};