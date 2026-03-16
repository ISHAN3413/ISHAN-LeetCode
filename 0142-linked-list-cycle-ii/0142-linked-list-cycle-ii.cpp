/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr)return nullptr;
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        bool detectnode = false;
        while(temp1!=nullptr && temp1->next!= nullptr){
            temp1 = temp1->next->next;
            temp2 = temp2->next;
            if(temp1==temp2){
                detectnode = true;
                break;
            }
        }
        if(detectnode){
            temp1 = head;
                while(temp1!=temp2){
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                }
                return temp1;
        }
        return nullptr;
    }
};