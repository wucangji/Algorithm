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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        helper (root, 1 , result);
        reverse(result.begin(), result.end());
        return result;
    }
    void helper(TreeNode *root, int level, vector<vector<int> > &result){
        if(!root) return;
        if(level > result.size()) result.push_back(vector<int>());
        result[level-1].push_back(root->val);
        helper(root->left, level+1, result);
        helper(root->right, level+1, result);
    }
};

// solution 1 
