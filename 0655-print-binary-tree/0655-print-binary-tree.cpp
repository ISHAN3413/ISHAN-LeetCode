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
    int fheight(TreeNode* root){
        if(root==NULL)return 0;

        return 1 + max(fheight(root->left) , fheight(root->right));
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int height = fheight(root);
        int m = height;
        int n = (1<<m) -1;
        vector<vector<string>> ans(m , vector<string>(n,""));
        f(root , 0 , 0 , n-1 , ans);
        return ans;
    }
    void f(TreeNode* root , int i , int j , int k ,vector<vector<string>> &ans ){
        if(root==NULL || j>k)return ;
        int mid = k+((j-k)/2);
        ans[i][mid] =to_string(root->val);
        f(root->left , i+1 , j , mid-1 ,ans);
        f(root->right , i+1 , mid+1 , k ,ans);
    }
};