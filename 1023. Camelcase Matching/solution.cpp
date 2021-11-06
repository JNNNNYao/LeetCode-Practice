class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans(queries.size(), false);
        for(int i = 0; i < queries.size(); i++){
            int q_idx = 0;  // index of query
            int p_idx = 0;  // index of pattern
            for(q_idx = 0; q_idx < queries[i].size(); q_idx++){
                if(islower(queries[i][q_idx])){
                    if(queries[i][q_idx] == pattern[p_idx]){
                        p_idx++;
                    }
                }
                else{
                    if(queries[i][q_idx] == pattern[p_idx]){
                        p_idx++;
                    }
                    else{
                        break;
                    }
                }
            }
            if(q_idx == queries[i].size() && p_idx == pattern.size()){
                ans[i] = true;
            }
        }
        return ans;
    }
};