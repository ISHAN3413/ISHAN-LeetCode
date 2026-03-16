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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr||left==right)return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        int i=1;
        while(i<left){
            prev = prev->next;
            i++;
        }
        ListNode* curr = prev->next;
        ListNode* pre = NULL;
        ListNode* next = NULL;
        for(i=0;i<right-left+1;i++){
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        prev->next->next = curr;
        prev->next = pre;
        return dummy.next;
    }
};