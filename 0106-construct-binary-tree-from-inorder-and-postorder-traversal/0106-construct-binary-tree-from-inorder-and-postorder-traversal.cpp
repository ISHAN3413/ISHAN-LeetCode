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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int , int> inmap;
        int n = inorder.size();
        for(int i = 0;i<n;i++){
            inmap[inorder[i]] = i;
        }
        return bt(inorder , 0 , n-1 , postorder , n-1 , 0 , inmap);
        
    }
    TreeNode* bt(vector<int>& inorder,int is , int ie, vector<int>& postorder ,int ps ,int pe , map<int , int> &inmap){
        if(is>ie || ps<pe)return NULL;
        TreeNode* root = new TreeNode(postorder[ps]);
        int a = inmap[root->val];
        int left = a-is;
        root->left = bt(inorder,is , a-1 , postorder ,pe+left-1,pe, inmap);
        root->right = bt(inorder ,a+1 , ie, postorder ,ps-1 , pe+left, inmap);
        return root;
    }
};