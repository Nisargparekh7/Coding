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
        
        getMinimumDifference(root->left);
        minimum = min(abs(root->val - prev),minimum);
        prev= root->val;
    
        getMinimumDifference(root->right);
        // minimum = min(abs(root->val - prev),minimum);
        // prev= root->val;
    }
    int getMinimumDifference(TreeNode* root) {
        
        solve(root);
        return minimum;
        
        
        
        
        
        
        
        
        
//         if(root->left ==NULL & root->right==NULL)return 0;
//         if (root->left!=NULL &&  root->right!=NULL ){
//             minimum=min(minimum, min(abs(root->val -  root->left->val),abs(root->val - root->right->val)));
//             getMinimumDifference(root->left);
//             getMinimumDifference(root->right);
//         }
//         else if(root->right==NULL){
//             minimum=min(minimum, abs(root->val -  root->left->val));
//             getMinimumDifference(root->left);
//         }
        
//         else if(root->left==NULL){
//              minimum=min(minimum, abs(root->val -  root->right->val));
//              getMinimumDifference(root->right);
//         }
        
        //return minimum;
    }
};