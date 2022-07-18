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
    int sum=0;
    int rangeSumBST(TreeNode* root, int low, int high) {
         rsum(root, low, high);
        return sum;
    }
    int rsum(TreeNode* root, int low, int high){
        if(root==NULL)return 0;
        
        if(root->val<low ){
            // sum+=root->val;
              rsum(root->right, low,high);
        }
        else if(root->val>high){
            rsum(root->left, low,high);
        }
        else{
            rsum(root->left, low,high);
            cout<<root->val<< " ";
            rsum(root->right, low,high);
            sum+=root->val;
            //sum+=root->val;
        }
        return sum;
    }
    
};