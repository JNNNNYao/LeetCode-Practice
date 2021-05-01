class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> diff(arr);
        for(int i = 0; i < diff.size(); i++){
            diff[i] = abs(diff[i] - x);
        }
        int pos = 0;
        for(int i = k; i < arr.size(); i++){
            if(diff[i] < diff[pos] || arr[i] == arr[pos]){
                pos++;
            }
            else if(diff[i] > diff[i-1]){
                break;
            }
        }
        vector<int> ans(arr.begin()+pos, arr.begin()+pos+k);
        return ans;
    }
};