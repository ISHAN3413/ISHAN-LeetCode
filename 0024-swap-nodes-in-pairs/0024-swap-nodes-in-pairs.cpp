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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* temp = head;
        while(temp!=nullptr && temp->next!=nullptr){
            ListNode* first = temp;
            ListNode* second = temp->next;
            first->next = second->next;
            second->next = first;
            prev->next = second;
            prev = first;
            temp = temp->next;
        }
        return dummy->next;
    }
};