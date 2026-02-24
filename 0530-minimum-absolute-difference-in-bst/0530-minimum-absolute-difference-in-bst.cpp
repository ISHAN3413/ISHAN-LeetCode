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
    TreeNode* prev = NULL;
    int getMinimumDifference(TreeNode* root) {
        if(root==NULL)return INT_MAX;
        int ans = INT_MAX;
        if(root->left!=NULL){
            int left = getMinimumDifference(root->left);
            ans = min(ans,left);
        }
        if(prev!=NULL){
            ans = min(ans , abs(root->val - prev->val));
        }
        prev = root;
        if(root->right!=NULL){
             int right = getMinimumDifference(root->right);
            ans = min(ans,right);
        }
        return ans;
    }
};