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
    int findSecondMinimumValue(TreeNode* root) {
        int first = root->val;
        long second = LONG_MAX;
        dfs(root,first,second);
        if(second == LONG_MAX)return -1;
        return second;
    }
    void dfs(TreeNode* root , int &first , long &second){
        if(root==nullptr)return ; 
       
        if(root->val>first && root->val<second){
            second = root->val;
        }
         dfs(root->left , first , second);
        dfs(root->right, first , second);
    }
};