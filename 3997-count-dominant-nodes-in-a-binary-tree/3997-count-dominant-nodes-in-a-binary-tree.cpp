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
    int countDominantNodes(TreeNode* root) {
        f(root);
        return ans;
    }
    int f(TreeNode* root){
        if(root == nullptr)return INT_MIN;
        
        int leftmax = f(root->left);
        int rightmax = f(root->right);

        int mx = max(root->val , max(leftmax , rightmax));
        if(root->val == mx){
            ans++;
        }
        return mx;
        }
    
};