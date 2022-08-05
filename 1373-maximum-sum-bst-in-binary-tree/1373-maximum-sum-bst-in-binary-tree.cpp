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
class nodevalue{
    public:
        int maxNode,  minNode,  sum;
      bool istrue;
      
};


class Solution {
public:
    int res= INT_MIN;
    int maxSumBST(TreeNode* root) {
         helper(root);
        return res>0 ? res :0; 
    }
    
    
    
    nodevalue helper(TreeNode* node){
        if(!node) {
            //nodevalue(int maxNode, int minNode, int sum){
        nodevalue bres;          
        bres.istrue = true;
        bres.maxNode = INT_MIN;
        bres.minNode = INT_MAX;
        bres.sum = 0;
        return bres;
        }
    
        
        auto left= helper(node->left);
        auto right= helper(node->right);
        
        nodevalue ans;
        
      ans.maxNode = max(node->val, max(left.maxNode, right.maxNode));
      ans.minNode = min(node->val, min(left.minNode, right.minNode));

      // Check if current tree is Bst or not ?
      ans.istrue = left.istrue && right.istrue && (left.maxNode < node->val && right.minNode > node->val);

      if(ans.istrue){
          ans.sum = left.sum + right.sum + node->val;
          ans.minNode = min(node->val, min(left.minNode, right.minNode));
          ans.maxNode = max(node->val, max(left.maxNode, right.maxNode));
      }
      else
          ans.sum = max(left.sum, right.sum);
      
      res = max(res, ans.sum);
      return ans;
    }
};