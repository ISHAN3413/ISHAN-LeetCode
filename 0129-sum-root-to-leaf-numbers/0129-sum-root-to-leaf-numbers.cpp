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
    void helper(TreeNode* root , int path , int&ans){
        if(root->left==NULL && root->right==NULL){
            ans+=path;
        }
        if(root->left!=NULL)helper(root->left,(path*10) +(root->left->val),ans);
        if(root->right!=NULL)helper(root->right,(path*10) +(root->right->val),ans);
    }
public:
    int sumNumbers(TreeNode* root) {
        if(root==NULL)return 0;
        int ans = 0;
        helper(root,root->val,ans);
        return ans;
    }
};