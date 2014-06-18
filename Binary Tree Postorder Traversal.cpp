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
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        TreeNode *p, *q;
        vector <int> result;
        p = root;
        //s.push(root);     // should use do while here. while doesn't work
        do {
            while(p){
                s.push(p);
                p = p->left;
                
            }
            q = NULL;
            while(!s.empty()){
                p = s.top();
                s.pop();
                if(!p->right || p->right == q) {   // right child has been visited or is NULL
                    result.push_back(p->val);
                    q = p;
                }
                else{
                    s.push(p);
                    p = p->right;
                    break;
                }
            }
        }while(!s.empty());
        return result;
    }
};