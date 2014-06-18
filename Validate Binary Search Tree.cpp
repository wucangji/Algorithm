/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return helper (root, INT_MIN, INT_MAX);
    }
    
    bool helper(TreeNode *root, int min, int max){
        if(!root) return true;  // return true~!
        return (root->val > min && root->val <max) && helper(root->left, min, root->val)
        && helper(root->right, root->val, max);
    }
};