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
    int height(TreeNode* root){
        if(root==NULL)return -1;
        int left=height(root->left);
        int right=height(root->right);
        int maxi=max(left,right)+1;
        return maxi;
    }
    void inorder(TreeNode* root,int &sum, int currentheight, int maxheight){
        if(root==NULL)return ;
        if(currentheight==maxheight){
            sum+=root->val;
        }
        inorder(root->left,sum,currentheight+1,maxheight);
        
        inorder(root->right,sum,currentheight+1,maxheight);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int sum=0;
        int maxheight=height(root);
        inorder(root,sum,0,maxheight);
        return sum;

       
    }
};