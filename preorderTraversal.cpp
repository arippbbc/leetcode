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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if(root==NULL) return res;
        stack<TreeNode *> parent;
        parent.push(NULL);
        TreeNode *temp = root;
        while(temp!=NULL){
            res.push_back(temp->val);
            if(temp->right) parent.push(temp->left);
            if(temp->left) parent.push(temp->right);
            if(temp->left==NULL && temp->right==NULL) {
                temp = parent.top();
                parent.pop(); 
                //temp = parent.top();
            }
        }
        return res;
    }
};
