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
    int ans = 2147483647;
    int lastValue = 2147483647;
    
public:
    int getMinimumDifference(TreeNode* root) {
        inOrder(root);
        return ans;
    }
    
    void inOrder(TreeNode* node) {
        if(node->left){
            inOrder(node->left);
        }
        if(node->val > lastValue && ans > node->val - lastValue){
            ans = node->val - lastValue;
        }
        lastValue = node->val;
        if(node->right){
            inOrder(node->right);
        }
    }
};