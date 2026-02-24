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
    bool helper(TreeNode* root, int target, int sum){
        if(root->left == NULL && root->right == NULL)return sum==target;
        bool left = false , right = false;
        if(root->left!=NULL)left = helper(root->left,target,sum+root->left->val);
        if(root->right!=NULL)right = helper(root->right,target,sum+root->right->val);
        return left||right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return 0;
        return helper(root,targetSum,root->val);
    }
};