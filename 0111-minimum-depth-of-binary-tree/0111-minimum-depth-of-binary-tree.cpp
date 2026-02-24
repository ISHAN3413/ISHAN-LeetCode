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
    void helper(TreeNode* root , int &ans , int sum){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL&&root->right==NULL){
            ans = min(sum,ans);
            return;
        }
        if(root->left!=NULL){
            helper(root->left,ans,sum+1);
        }
        if(root->right!=NULL){
            helper(root->right,ans,sum+1);
        }
    }
    int minDepth(TreeNode* root) {
        if(root==NULL)return 0;
        int ans = INT_MAX;
        helper(root,ans,1);
        return ans;
    }
};