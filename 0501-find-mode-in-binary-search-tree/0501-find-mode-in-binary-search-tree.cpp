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
    vector<int> ans;
    int currval;
    int maxcount = 0;
    int currentcount = 0;

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        
        return ans;
    }

    void handling(int val){
        if(val!=currval){
            currval = val;
            currentcount = 0;
        }
        currentcount++;
        if(currentcount>maxcount){
            maxcount = currentcount;
            ans.clear();
            ans.push_back(val);
        }
        else if(currentcount==maxcount){
            ans.push_back(val);
        }
    }

    void inorder(TreeNode* root){
        if(root==nullptr)return;
        inorder(root->left);
        handling(root->val);
        inorder(root->right);

    }
};