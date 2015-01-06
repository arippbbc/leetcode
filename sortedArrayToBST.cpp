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
        if(num.size()==2) {
            TreeNode *n0 = new TreeNode(num[0]);
            TreeNode *n1 = new TreeNode(num[1]);
            n0->right = n1;
            return n0;
        }
        
        if(num.size()==3) {
            TreeNode *n0 = new TreeNode(num[0]);
            TreeNode *n1 = new TreeNode(num[1]);
            TreeNode *n2 = new TreeNode(num[2]);
            n1->left = n0;
            n1->right = n2;
            return n1;
        }
        
        else{
            TreeNode *head = new TreeNode(num[num.size()/2]);
            vector<int> v1(num.begin(), num.begin()+num.size()/2), v2(num.begin()+num.size()/2+1, num.end());
            head->left = sortedArrayToBST(v1);
            head->right = sortedArrayToBST(v2);
            return head;
        }
    }
};
