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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root ==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        int flag =0;
        while(!q.empty()){
            vector<int> temp;
            int size = q.size();
            
            for(int i=0;i<size;i++){
                TreeNode *x=q.front();
                q.pop();
                temp.push_back(x->val);
            
                if(x->left){
                    q.push(x->left);
                }
                
                if(x->right){
                    q.push(x->right);
                }
            }
            if(flag==1){  
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
                flag=0;
            }
            else{
                //cout<< flag<< " ";
                ans.push_back(temp);
                flag=1;
            }
            
            
            
        }
        return ans;

    }
};