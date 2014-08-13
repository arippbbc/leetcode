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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(num.size()<1) return NULL;
        if(num.size()==1) return new TreeNode(num[0]);
        if(num.size()==2) 
        TreeNode *head = new TreeNode()
    }
};
