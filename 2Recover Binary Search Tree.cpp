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
    void recoverTree(TreeNode *root) {
        //正扫 降序前一个，反扫 升序前一个  swap这两个
        
        //if(!root ) return ;
        
        vector<TreeNode *> v;
        TreeNode * p =NULL;
        getTreeVals(v,root,p);
        swap(v.front()->val,v.back()->val);
    }
    
    void getTreeVals(vector<TreeNode *> &v, TreeNode *root, TreeNode *&pre ){
        if(!root) return;
        getTreeVals(v,root->left,pre);
        if(pre && pre->val > root->val){
            if(v.empty()) v.push_back(pre);    // 若就一对，那就是，若两对，刚好是最前和最后！！牛逼啊
            v.push_back(root);
        }
        pre = root;
        getTreeVals(v,root->right,pre);    //  pre 理论应该都比  root 小 
    }
};