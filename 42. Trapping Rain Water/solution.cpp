// Two Pointers
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 1;
        int right = n-2;
        int left_max = height[0];
        int right_max = height[n-1];
        int ans = 0;
        while (left <= right) {
            if (height[left] > left_max)
                left_max = height[left];
            if (height[right] > right_max)
                right_max = height[right];
            
            if (left_max < right_max) {
                ans += (left_max - height[left]);
                left++;
            }
            else {
                ans += (right_max - height[right]);
                right--;
            }
        }
        return ans;
    }
};
// DP
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left_bar[n];
        int right_bar[n];
        left_bar[0] = height[0];
        for (int i = 1; i < n; i++) {
            left_bar[i] = max(left_bar[i-1], height[i]);
        }
        right_bar[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--) {
            right_bar[i] = max(right_bar[i+1], height[i]);
        }
        int ans = 0;
        for (int i = 1; i < n-1; i++){
            ans += min(left_bar[i], right_bar[i]) - height[i];
        }
        return ans;
    }
};