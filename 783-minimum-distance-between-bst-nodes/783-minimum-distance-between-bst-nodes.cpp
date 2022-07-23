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
    int minimum=INT_MAX;
    int prev=INT_MAX;
    
    void solve(TreeNode* root){
        if(root==NULL ){
            //prev= root->val;
            return;
        }
        
        minDiffInBST(root->left);
        minimum = min(abs(root->val - prev),minimum);
        prev= root->val;
    
        minDiffInBST(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        solve(root);
        return minimum;
    }
};