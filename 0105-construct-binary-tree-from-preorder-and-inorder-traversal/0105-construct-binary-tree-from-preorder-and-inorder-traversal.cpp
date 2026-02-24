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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inmap;
        for(int i = 0;i<inorder.size();i++){
            inmap[inorder[i]] = i;
        }
        return bt(preorder , 0 ,inorder.size()-1 , inorder , 0 , inorder.size()-1,inmap );
        
    }
    TreeNode* bt(vector<int>& preorder,int ps , int pe , vector<int>& inorder,int is , int ie , map<int,int> &inmap){
        if(ps>pe || is>ie)return NULL;
        TreeNode* root = new TreeNode(preorder[ps]);

        int a = inmap[root->val];
        int left = a-is;

        root->left = bt(preorder , ps+1 ,ps+left , inorder , is , a-1 ,inmap );
        root->right = bt(preorder , ps+left+1 , pe , inorder , a+1 , ie , inmap);
        return root;
    }
};