/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int x=0;
    int kthSmallest(TreeNode* root, int k) {
      
        helper(root, k);
     
        return x;
    }
    
    void helper(TreeNode * root, int &k){
        if(root==NULL)return;
        
        helper(root->left,k);
        if(--k==0){
            x=root->val;
            return;
        }
        helper(root->right,k);
    }
};