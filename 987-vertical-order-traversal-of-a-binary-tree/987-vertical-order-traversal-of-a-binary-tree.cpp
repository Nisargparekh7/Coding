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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> m;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            TreeNode* node= a.first;
            int x= a.second.first, y=a.second.second;
            m[x][y].insert(node->val);
            if(node->left){
                q.push({node->left, {x-1,y+1}});
            }
            if(node->right){
                q.push({node->right, {x+1,y+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto i:m){
            vector<int>col;
            for(auto j: i.second){
                col.insert(col.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};