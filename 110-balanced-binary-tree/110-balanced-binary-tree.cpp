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
    int cnt=0;
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return 1;
        int x= height(root->left);
        int y= height(root->right);
        
        if (abs(x-y)<=1 && isBalanced(root->left) &&isBalanced(root->right) )return true;
        return false ; 
    }
    
    int height(TreeNode* root){
        if(root==NULL)return 0;
        else{
        cnt = max(height(root->left),height(root->right));
            cnt++;
        }   
        return cnt;
    }
};