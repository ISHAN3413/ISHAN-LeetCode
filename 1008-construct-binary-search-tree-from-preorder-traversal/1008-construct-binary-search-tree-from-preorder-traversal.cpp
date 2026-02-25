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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return build(preorder,index,INT_MIN,INT_MAX);
    }
private:
    TreeNode* build(vector<int>& preorder,int& index,int lowerbound,int upperbound){
        if(index>=preorder.size()||preorder[index]<lowerbound||preorder[index]>upperbound){
            return nullptr;
        }
        int rootval=preorder[index++];
        TreeNode* root=new TreeNode(rootval);
        root->left=build(preorder,index,lowerbound,rootval);
        root->right=build(preorder,index,rootval,upperbound);
        return root;
    }
};