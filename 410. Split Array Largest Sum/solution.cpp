class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int min = INT_MIN, max = 0;
        for(auto num: nums){
            if(num > min){  // min is actually max in nums
                min = num;
            }
            max += num;
        }
        int mid = (min + max) / 2;
        while(min != max){
            int sum = 0;
            int cnt = 1;    // # of split
            for(int i = 0; i < nums.size(); i++){
                sum += nums[i];
                if(sum > mid){
                    sum = nums[i];
                    cnt++;
                }
            }
            if(cnt <= m){
                max = mid;
                mid = (min + max) / 2;
            }
            else{
                min = mid + 1;
                mid = (min + max) / 2;
            }
        }
        return mid;
    }
};