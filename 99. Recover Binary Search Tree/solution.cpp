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
    TreeNode* prev = NULL;
    int numMistake = 0; // 1: when first pair invalid is the mistake pair
                        // 2: otherwise
    TreeNode* node1;    // wrong node with larger value
    TreeNode* node2;    // wrong node with smaller value
    
    void inOrder(TreeNode* root) {
        if(!root){
            return;
        }
        inOrder(root->left);
        if(prev == NULL){   // start from the smallest node
            prev = root;
        }
        if(prev->val > root->val){
            if(numMistake == 0){
                node1 = prev;
                node2 = root;
                numMistake++;
            }
            else{
                node2 = root;
                return;
            }
        }
        prev = root;
        inOrder(root->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
        inOrder(root);
        swap(node1->val, node2->val);
    }
};