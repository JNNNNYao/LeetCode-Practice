class Solution {
public:
    int recursive(vector<int>& nums, int min, int max) {
        int mid = (min + max)/2;
        if(max == min){
            return nums[min];
        }
        else if(nums[max] > nums[min]){
            return nums[min];
        }
        else if(nums[mid] < nums[min]){
            max = mid;
            return recursive(nums, min, max);
        }
        else if(nums[max] < nums[mid]){
            min = mid + 1;
            return recursive(nums, min, max);
        }
        else{ // nums[max] == nums[mid] && nums[mid] == nums[min]
            return std::min(recursive(nums, min, mid), recursive(nums, mid+1, max));
        }
    }
    
    int findMin(vector<int>& nums) {
        int min = 0, max = nums.size()-1;
        return recursive(nums, min, max);
    }
};