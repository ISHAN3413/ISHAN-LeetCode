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
    int maxSum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        h(root);
        return maxSum;
    }
    int h(TreeNode* root){
        if(!root)return 0;

        int left = max(0 , h(root->left));
        int right = max(0 , h(root->right));

        maxSum = max(maxSum , root->val + left + right);

        return root->val + max(left , right);
    }
};