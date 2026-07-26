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
    ListNode* sortList(ListNode* head) {
        std::vector<int> a;
        ListNode* temp=head;
        while(temp!=NULL){
            a.push_back(temp->val);
            temp=temp->next;
        }
        std::sort(a.begin(),a.end());
        temp=head;
        for(int i=0;i<a.size();i++){
            temp->val=a[i];
            temp=temp->next;
        }
        return head;
    }
};