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
    int ans = 0;
    int maxdepth = -1;
    int findBottomLeftValue(TreeNode* root) {
        f(root , 0);
        return ans;
    }
    void f(TreeNode* root , int a){
        if(root==NULL)return ;
        if(maxdepth<a){
            maxdepth = a;
            ans = root->val;
        }
        f(root->left , a+1);
        f(root->right, a+1);

    }
    
};