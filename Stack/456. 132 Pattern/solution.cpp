class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int first[n];   // best candidate of the first integer at each position
                        // this will be a descending array
        first[0] = nums[0];
        for(int i = 1; i < n; i++){
            first[i] = min(first[i-1], nums[i-1]);
        }
        stack<int> third;   // candidate of the third integer
                            // this will be an descending stack
        third.push(nums[n-1]);
        for(int i = n-2; i > 0; i--){   // for loop run through all posible candidate of the second integer
            while(!third.empty() && first[i] >= third.top()){
                third.pop();
            }
            if(!third.empty() && nums[i] > third.top()){
                return true;
            }
            third.push(nums[i]);
        }
        return false;
    }
};



class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int second;
        for(int i = 0; i < n; i++){
            second = -2147483647;
            for(int j = i+1; j < n; j++){
                if(nums[j] > nums[i] && second < nums[j]){
                    second = nums[j];
                }
                if(nums[j] > nums[i] && nums[j] < second){
                    return true;
                }
            }
        }
        return false;
    }
};