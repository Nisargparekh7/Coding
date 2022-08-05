// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class nodevalue{
//     public:
//         int maxNode,  minNode,  sum;
//       bool istrue;
      
// };


// class Solution {
// public:
//     int res= INT_MIN;
//     int maxSumBST(TreeNode* root) {
//          helper(root)
//         return res>0 ? res :0; 
//     }
    
    
    
//     nodevalue helper(TreeNode* node){
//         if(!node) {
//             //nodevalue(int maxNode, int minNode, int sum){
//         nodevalue bres;          
//         bres.istrue = true;
//         bres.maxNode = INT_MIN;
//         bres.minNode = INT_MAX;
//         bres.sum = 0;
//         return bres;
//         }
    
        
//         auto left= helper(node->left);
//         auto right= helper(node->right);
        
//         nodevalue ans;
        
//       ans.maxNode = max(node->val, max(left.max, right.max));
//       ans.minNode = min(node->val, min(left.min, right.min));

//       // Check if current tree is Bst or not ?
//       ans.istrue = left.istrue && right.istrue && (left.maxNode < node->val && r.min > root->val);

//       if(ans.isbst){
//           ans.sum = l.sum + r.sum + root->val;
//           ans.min = min(root->val, min(l.min, r.min));
//           ans.max = max(root->val, max(l.max, r.max));
//       }
//       else
//           ans.sum = max(l.sum, r.sum);
      
//       res = max(res, ans.sum);
//       return ans;
//     }
// };



class Solution {
public:
    class bst {
    public:
      bool isbst;
      int max;
      int min;
      int sum;
    };

    bst Bst(TreeNode* root) {

      if (root == nullptr)
      {  
        bst bres;            // Base Case
        bres.isbst = true;
        bres.max = INT_MIN;
        bres.min = INT_MAX;
        bres.sum = 0;
        return bres;
      }
      bst l = Bst(root->left); // left sub-tree
      bst r = Bst(root->right); // right sub-tree

      bst ans;

      ans.max = max(root->val, max(l.max, r.max));
      ans.min = min(root->val, min(l.min, r.min));

      // Check if current tree is Bst or not ?
      ans.isbst = l.isbst && r.isbst && (l.max < root->val && r.min > root->val);

      if(ans.isbst){
          ans.sum = l.sum + r.sum + root->val;
          ans.min = min(root->val, min(l.min, r.min));
          ans.max = max(root->val, max(l.max, r.max));
      }
      else
          ans.sum = max(l.sum, r.sum);
      
      res = max(res, ans.sum);
      return ans;
    }
    
    int res = INT_MIN;
    int maxSumBST(TreeNode* root) {
        Bst(root);
        return res > 0 ? res : 0;
    }
};