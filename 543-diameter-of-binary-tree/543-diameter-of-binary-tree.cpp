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
    int ans;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        height(root);
        return ans;
    }
    
    int height(TreeNode * root){
        if(!root) return 0;
        int LH= height(root->left);
        int RH= height(root->right);
        
        ans=max(ans, LH+RH);
        return 1 + max(LH, RH);
    }
};