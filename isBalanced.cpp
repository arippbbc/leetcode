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
    int maxDepth(TreeNode *root){
        int res=0;
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        else return 1+max(maxDepth(root->right), maxDepth(root->left));
    }
    
    bool isBalanced(TreeNode *root) {
        if(root==NULL) return true;
        if(root->left==NULL && root->right==NULL) return true;
        return isBalanced(root->left) && isBalanced(root->right) && abs(maxDepth(root->left)-maxDepth(root->right))<=1;
    }
};
