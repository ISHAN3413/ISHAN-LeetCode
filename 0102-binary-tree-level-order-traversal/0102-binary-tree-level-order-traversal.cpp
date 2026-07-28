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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        f(root,ans,0);
        return ans;
    }
    void f(TreeNode* root , vector<vector<int>> &ans,int i){
        if(root==nullptr)return;
        if(i==ans.size()){
            ans.push_back({});
        }
        ans[i].push_back(root->val);
        f(root->left , ans,i+1);
        f(root->right,ans,i+1);
    }
};