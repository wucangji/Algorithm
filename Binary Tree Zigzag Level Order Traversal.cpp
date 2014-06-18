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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        helper(root, 1, true, result);   // no need to set up a new bool, true is enough
        return result;  // don't forget to return
    }
private:
    void helper(TreeNode *root, int level, bool inorder,vector<vector<int> >&result){     // the helper is void
        if(!root) return;
        if(level > result.size()) result.push_back(vector<int>());
        if(inorder) {
            result[level-1].push_back(root->val);
        }
        else{
            result[level-1].insert(result[level-1].begin(),root->val);
        }
        helper(root->left, level+1, !inorder, result);
        helper(root->right, level+1, !inorder, result);
    }
};