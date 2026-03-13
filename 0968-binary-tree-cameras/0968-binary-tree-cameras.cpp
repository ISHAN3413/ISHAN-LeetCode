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
    int ncam;
    int minCameraCover(TreeNode* root) {
        ncam = 0;
        pair<bool,bool> temp = cntcamera(root);
        if(!temp.second){
            ncam++;
        }
        return ncam;
    }
    pair<bool,bool> cntcamera(TreeNode* root){
        if(root==NULL){
            return {false,true};
        }
        pair<bool,bool> L = cntcamera(root->left);
        pair<bool,bool> R = cntcamera(root->right);
        bool hascam = false;
        bool ismon = false;
        if(L.first || R.first){
            ismon = true;
        }
        if(!L.second || !R.second){
            ismon = true;
            hascam = true;
            ncam++;
        }
        return {hascam,ismon};
    }
};