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
    ListNode* deleteMiddle(ListNode* head) {
        int i = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            i++;
            temp=temp->next;
        }
        if(i==1)return NULL;
        if(i==2){
            head->next = NULL;
            return head;
        }
        int n = (i/2) +1;
        temp=head;
        ListNode* pre = new ListNode(0,temp);
        n--;
        while(n!=0){
            temp=temp->next;
            pre = pre->next;
            n--;
        }
        pre->next = pre->next->next;
        temp->next = NULL;
        return head;

    }
};