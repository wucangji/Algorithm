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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return helper(inorder,0,inorder.size()-1, postorder,0, postorder.size()-1);
    }
    
    TreeNode *helper(vector<int> &inorder, int in_start, int in_end, vector<int> &postorder, int post_start, int post_end){
        if(in_end<in_start || in_end-in_start != post_end-post_start) return NULL;
        int value = postorder[post_end];
        TreeNode *root = new TreeNode(value);
        int root_index;
        for(int i = in_start; i<= in_end; i++){   // <=   !
            if(inorder[i] == value) {
                root_index = i;
                break;
            }
        }
        int innodes = root_index-in_start;
        root->left = helper(inorder,in_start,root_index-1, postorder,post_start, post_start+innodes-1);
        root->right = helper(inorder,root_index+1,in_end, postorder,post_start+innodes, post_end-1);
        return root;
    }
};