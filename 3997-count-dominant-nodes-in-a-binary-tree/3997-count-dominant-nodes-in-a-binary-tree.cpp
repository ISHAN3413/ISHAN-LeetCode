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
    int countDominantNodes(TreeNode* root) {
        int ans = 0;
        if(root==nullptr)return 0;
        if(root->val == f(root))ans++;
        ans+=countDominantNodes(root->left) + countDominantNodes(root->right);
        return ans;
    }
    int f(TreeNode* root){
        int ans = root->val;
        if(root->left == NULL && root->right==NULL)return root->val;
        if(root->left !=NULL)ans = max(ans , f(root->left));
        if(root->right != NULL)ans = max(ans , f(root->right));
        return ans;
        }
};