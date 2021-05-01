class Solution {
public:
    static bool comp(vector<int> a, vector<int> b) {
        // reverse height for the envlopes with same width
        return (a[0] == b[0]) ? a[1] > b[1] : a[0] < b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> vec;
        for(auto it: envelopes){
            auto iter = lower_bound(vec.begin(), vec.end(), it[1]);
            if(iter == vec.end()){
                vec.push_back(it[1]);
            }
            else{
                *iter = it[1];
            }
        }
        return vec.size();
    }
};