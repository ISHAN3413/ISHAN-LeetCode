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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* ans = new ListNode(-1);
        ListNode* result = ans;
        int rem = 0;
        while(temp1!=nullptr &&temp2!=nullptr){
            int sum = temp1->val + temp2->val+rem;
            rem = sum/10;
            ListNode* n = new ListNode(sum%10);
            ans->next = n;
            ans=ans->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=nullptr){
            int sum = temp1->val+rem;
            rem = sum/10;
            ListNode* n = new ListNode(sum%10);
            ans->next = n;
            ans=ans->next;
            temp1=temp1->next;
        }
        while(temp2!=nullptr){
            int sum = temp2->val+rem;
            rem = sum/10;
            ListNode* n = new ListNode(sum%10);
            ans->next = n;
            ans=ans->next;
            temp2=temp2->next;
        }
        if(rem!=0){
            ListNode* n = new ListNode(rem);
            ans->next = n;
            ans=ans->next;
        }

        return result->next;
        }
};