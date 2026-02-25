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
private:
TreeNode* inorder(TreeNode* root,int val){
    if(root==NULL)return root;
    TreeNode* leftResult = inorder(root->left, val);
    if (leftResult != nullptr) return leftResult;
    if(root->val==val)return root;
    return inorder(root->right,val);
}
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return inorder(root, val);
    }
};