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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> m;
        for(int i=0;i<inorder.size();i++){
           m[inorder[i]]= i; 
        }
        reverse(postorder.begin(), postorder.end());
        TreeNode* root = helper(postorder, 0 , postorder.size()-1, inorder, 0, inorder.size()-1 , m);
        
        return root;
    }
    
    TreeNode* helper(vector<int> &postorder, int posstart, int posend, 
                     vector<int> &inorder, int instart, int inend, map<int,int> &m ){
        if(posstart>posend || instart>inend)return NULL;
         
         TreeNode* root = new TreeNode(postorder[posstart]); 
        int inroot= m[root->val];
        int numsleft= inend-inroot;
        
        root->right =helper(postorder, posstart+1, posstart+numsleft, 
                          inorder, inroot+1,inend, m);
        
        root->left =helper(postorder, posstart+numsleft+1, posend, 
                          inorder, instart,inroot-1, m);
        
        return root;
    }
};