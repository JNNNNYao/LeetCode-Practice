class Solution {
public:
    static bool comp(vector<int> &v0, vector<int> &v1) {
        return (v0[1] < v1[1]);   // sort based on right
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comp);
        int curr_right = INT_MIN;
        int ans = 0;
        for(auto v: pairs){ // always choose the pair with smallest right
            if(v[0] > curr_right){
                ans++;
                curr_right = v[1];
            }
        }
        return ans;
    }
};