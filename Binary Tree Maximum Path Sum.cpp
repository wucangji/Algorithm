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
    int maxPathSum(TreeNode *root) {
        
        dfs(root);
        return max_sum;
    }
    int max_sum = INT_MIN;
    int dfs(TreeNode *root){
        if(!root) return 0;
        int l=dfs(root->left);
        int r=dfs(root->right);
        int sum = root->val;
        if(l>0) sum+=l;
        if(r>0) sum+=r;
        max_sum = max(max_sum,sum);
        return max(r,l)>0? max(r,l)+root->val:root->val;  // return 的可以不是要的值，要的是maxsum   
        //中间可以dfs return 的是一半（val+l     or  val+r）
    }
};