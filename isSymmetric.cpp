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
    bool checkSymmetric(TreeNode *n1, TreeNode *n2){
        if(!n1 && !n2) return true;
        if((!n1 && n2) || (n1 && !n2)) return false;
        return (n1->val == n2->val) && checkSymmetric(n1->left, n2->right) && checkSymmetric(n1->right, n2->left); 
    }
    bool isSymmetric(TreeNode *root) {
        if(!root) return true;
        return checkSymmetric(root->left, root->right);
    }
};
