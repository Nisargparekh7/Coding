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
    bool isValidBST(TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return true;
        return helper(root,LONG_MIN, LONG_MAX);
    }
    bool helper(TreeNode* root, long mini, long maxa){
        if(root==NULL) return true;
        if(root->val <= mini || root->val >=maxa) return false;
        return helper(root->left, mini, root->val) && helper(root->right, root->val, maxa) ;
    }
};