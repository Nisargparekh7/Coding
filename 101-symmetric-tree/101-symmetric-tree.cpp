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
    bool isSymmetric(TreeNode* root) {
        return helper(root->left, root->right);
        
    }
    bool helper(TreeNode* l1,TreeNode* r1){
        // if(root==NULL) return;
        if((l1==NULL && r1!=NULL) || (l1!=NULL && r1==NULL)) return 0;
        if(l1==NULL && r1==NULL) return 1;
        if(l1->val==r1->val){
            return helper(l1->left, r1->right) && helper(l1->right, r1->left);
        }
        return 0;
    }
};