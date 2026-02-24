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
    vector<int> largestValues(TreeNode* root) {
        if(!root)return {};
        queue<pair<TreeNode*,int>> q;
        vector<int> ans;
        q.push({root,0});
        int cl = 0;
        int maxi = root->val;
        while(!q.empty()){
            TreeNode* t = q.front().first;
            int level = q.front().second;
            q.pop();
            if(level!=cl){
                ans.push_back(maxi);
                cl=level;
                maxi = t->val;
            }
            maxi = max(maxi , t->val);
            if(t->left!=nullptr){
                q.push({t->left,level+1});
            }
            if(t->right!=nullptr){
                q.push({t->right,level+1});
            }
        }
        ans.push_back(maxi);
        return ans;
    }
};