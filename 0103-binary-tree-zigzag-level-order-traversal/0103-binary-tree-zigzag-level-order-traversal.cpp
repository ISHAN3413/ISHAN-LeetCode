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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root==NULL)return ans;
        q.push(root);
        bool flag = 1;
        while(!q.empty()){
            int size = q.size();
            vector<int> a(size) ;     
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                int index = flag? i : (size-i-1);
                a[index] = node->val;
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right); 
            }
            ans.push_back(a);
           flag = !flag;
        }
        return ans;
    }
};