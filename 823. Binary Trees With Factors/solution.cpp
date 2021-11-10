class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, unsigned long long> DP;  // deal with int overflow
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            int parent = arr[i];
            DP[parent] = 1;
            for (int j = 0; j < i; j++) {
                int left = arr[j];
                if (parent % left == 0) {
                    auto it = DP.find(parent/left);
                    if (it != DP.end()) {
                        DP[parent] += (DP[left] * it->second);
                        DP[parent] %= 1000000007;
                    }
                }
            }
            ans += DP[parent];
            ans %= 1000000007;
        }
        return ans;
    }
};