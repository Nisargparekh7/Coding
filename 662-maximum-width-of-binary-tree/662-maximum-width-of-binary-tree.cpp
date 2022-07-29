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
    int widthOfBinaryTree(TreeNode* root) {
        if (root==NULL)return 0;
        int ans=INT_MIN;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            int mini= q.front().second;
            int first, last;
            for(int i=0;i<size;i++){
                long int currid= q.front().second - mini;
                TreeNode* N= q.front().first;
                q.pop();
                if(i==0)first=currid;
                if(i==size-1)last= currid;
                if(N->left){
                    q.push({N->left,currid*2+1});    
                }
                if(N->right){
                    q.push({N->right,currid*2+2});    
                }
            }
            ans= max(ans, last-first+1);
        }
        return ans;
    }
};