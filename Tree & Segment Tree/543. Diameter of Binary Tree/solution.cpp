/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int ans = 0;
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int left = findMax(root->left);
        int right = findMax(root->right);
        if(left + right > ans){
            ans = left + right;
        }
        return ans;
    }
    
    int findMax(TreeNode* root) {
        if(!root){
            return 0;
        }
        int left = findMax(root->left);
        int right = findMax(root->right);
        if(left + right > ans){
            ans = left + right;
        }
        return max(left, right) + 1;
    }
};