/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m , vector<int>(n, -1));
        vector<int> a;
        f(head , a);
        bool l = false;
        bool r = true;
        bool u = false;
        bool d = false;
        int i = 0;
        int j = 0;
        int b = 0;
        for(int k = 1;k<=m*n ; k++){
            if(b>=a.size())break;
            ans[i][j] = a[b];
            b++;
            if(r){
                if(j+1<n && ans[i][j+1]==-1){
                    j++;
                }
                else{
                    r=false;
                    d=true;
                    i++;
                }
            }
            else if(d){
                if(i+1<m && ans[i+1][j]==-1){
                    i++;
                }
                else{
                    d=false;
                    l=true;
                    j--;
                }
            }
            else if(l){
                if(j-1>=0 && ans[i][j-1]==-1){
                    j--;
                }
                else{
                    l=false;
                    u=true;
                    i--;
                }
            }
            else if(u){
                if(i-1>=0 && ans[i-1][j]==-1){
                    i--;
                }
                else{
                    u=false;
                    r=true;
                    j++;
                }
            }
        }
        return ans;
    }
    void f(ListNode* head , vector<int>&a){
        if(head==NULL)return ;
        a.push_back(head->val);
        f(head->next , a);
    }
};