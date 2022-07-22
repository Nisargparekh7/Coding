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
    //int cnt=0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root==NULL )return 0;
        
        if(!root->left && !root->right ) {
            targetSum-=root->val;
            if(targetSum==0)return true;
            else return false;
            }
        

        
        //if(root->val <=targetSum){
            // cout<< root->val<< "  ";
            targetSum-=root->val;
            // cout<<targetSum<< "  ";
            return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
        
        
        
       return 0;
    }
};