class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min = 1, max = INT_MIN;
        for(auto it: piles){
            if(it > max){
                max = it;
            }
        }
        int mid = (min + max)/2;
        while(1){
            unsigned long long time = 0;
            for(auto it: piles){
                time += ceil(double(it)/mid);
            }
            if(time <= h){
                if(min == mid){
                    break;
                }
                max = mid;
                mid = (min + max)/2;
            }
            else{
                min = mid+1;
                mid = (min + max)/2;
            }
        }
        return mid;
    }
};