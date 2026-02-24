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
    void find(TreeNode* root, int target , long long sum , int &ans){
        if(!root){
            return;
        }
        sum+=root->val;
        if(sum==target){
            ans++;
        }
        find(root->left,target,sum,ans);
        find(root->right,target,sum,ans);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        if(root==NULL)return ans;
        find(root,targetSum,0LL,ans);
        ans+=pathSum(root->left,targetSum);
        ans+=pathSum(root->right,targetSum);
        return ans;
    }
};