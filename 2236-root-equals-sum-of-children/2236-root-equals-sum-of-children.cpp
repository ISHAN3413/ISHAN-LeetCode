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
    void inorder(TreeNode* root,int &sum){
        if(root==NULL)return ;
        inorder(root->left,sum);
        sum+=root->val;
        inorder(root->right,sum);
    }
public:
    bool checkTree(TreeNode* root) {
        int sum1=root->val;
        int sum2=0;
        inorder(root,sum2);
        if(sum2==(2*sum1))return 1;
        return 0;
    }
};