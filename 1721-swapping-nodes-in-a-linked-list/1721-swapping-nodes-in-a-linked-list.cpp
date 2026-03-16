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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr)return head;
        int count = 0;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* temp = head;
        ListNode* prev1 = &dummy;
        ListNode* prev2 = &dummy;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        for(int i=1;i<k;i++){
           prev1 = prev1->next; 
        }
        for(int j=1;j<count-k+1;j++){
           prev2 = prev2->next; 
        }
        ListNode* first= prev1->next;
        ListNode* second= prev2->next;
     
        if(first==second)return dummy.next;
        else if(first->next==second){
            first->next = second->next;
            prev1->next = second;
            second->next = first;
        }
        else if(second->next==first){
            second->next = first->next;
            prev2->next = first;
            first->next = second;
        }
        else{
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            prev1->next = second;
            second->next = temp1;

            prev2->next = first;
            first->next = temp2;
        }
        return dummy.next;
    }
};