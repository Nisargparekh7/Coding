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
    int i=0;
    TreeNode* bstFromPreorder(vector<int>& preorder, int max_val = INT_MAX) {
        if (i == preorder.size() || preorder[i] > max_val) return NULL;
        
        TreeNode* root = new TreeNode(preorder[i++]);
        
        root->left = bstFromPreorder(preorder, root->val);
        root->right = bstFromPreorder(preorder, max_val);
        
        return root;
        
        
        
        
//         if (preorder.size() == 0){  // If vector is empty, return NULL
//             return NULL;
//         }
        
//         TreeNode* root = new TreeNode(preorder[0]); 
//         for (int i = 1; i < preorder.size(); i++){  // Traversing the vector
//             bool done = false;  // Marker to indicate when the vector value has been added to the tree
//             TreeNode* current = root;   // Current is used to traverse the tree we're creating
            
//             while (done == false){
//                 if (preorder[i] < current->val){    
//                     if (current->left == NULL){ 
//                         current->left = new TreeNode(preorder[i]);
//                         done = true;    
//                     }
//                     else{   
//                         current = current->left;
//                     }
//                 }
//                 else{   
//                     if (current->right == NULL){ // Add the vector value to tree if spot is available
//                         current->right = new TreeNode(preorder[i]);
//                         done = true; // Vector value added, therefore break out of while loop
//                     }
//                     else{
//                         current = current->right;   // No spot available, keep traversing tree
//                     }
//                 }
//             }
//         }
        
//         return root;
        
        
    }
};