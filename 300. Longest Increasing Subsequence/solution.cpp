class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> seq;
        for(int i = 0; i < nums.size(); i++){
            auto it = std::upper_bound (seq.begin(), seq.end(), nums[i]);
            if(it != seq.begin() && *(it-1) == nums[i]){    // upper_bound return something weird
                continue;
            }
            else if(it == seq.end()){
                seq.push_back(nums[i]);
            }
            else{
                *it = nums[i];
            }
        }
        return seq.size();
    }
};



class Solution {
public:
    class Node{
    public:
        Node(int val){
            this->val = val;
            this->left = nullptr;
            this->right = nullptr;
        }
        int val;
        Node *left;
        Node *right;
    };
    
    int lengthOfLIS(vector<int>& nums) {
        Node *root = new Node(nums[0]);
        int longest = 1;
        for(int i = 1; i < nums.size(); i++){
            recursive(root, nums[i], &longest);
        }
        return longest;
    }
    
    void recursive(Node *root, int data, int *longest) {
        if(data < root->val){
            root->val = data;
        }
        else if(data > root->val){
            if(root->right == nullptr){
                *longest = *longest + 1;
                root->right = new Node(data);
                return;
            }
            else{
                recursive(root->right, data, longest);
                return;
            }
        }
        else{
            return;
        }
    }
};