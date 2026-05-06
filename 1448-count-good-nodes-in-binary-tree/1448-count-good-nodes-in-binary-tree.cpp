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
    int goodNodes(TreeNode* root) {
        return f(root,root->val);
    }
    int f(TreeNode* root, int pre){
        if(root==nullptr)return 0;
        if(root->val >= pre){
            return 1+f(root->left,root->val)+f(root->right,root->val);
        }
        else return f(root->left,pre)+f(root->right,pre);
    }
};