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
    void inorder(TreeNode* root,int &sum1){
        if(root==NULL){
            return ;
        }
        inorder(root->left,sum1);
        if(root->left!=NULL && root->left->left==NULL && root->left->right==NULL)sum1+=root->left->val;
        inorder(root->right,sum1);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        inorder(root,sum);
        return sum;
    }
};