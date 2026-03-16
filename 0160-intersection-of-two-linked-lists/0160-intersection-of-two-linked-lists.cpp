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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1= headA;
        std::unordered_map<ListNode*,int> m;
        while(temp1!=nullptr){
           m[temp1]=1;
           temp1 = temp1->next;
        }
        temp1 = headB;
        while(temp1!=nullptr){
            if(m.find(temp1) != m.end() )return temp1;
            temp1 = temp1->next;
        }
        return nullptr;
    }
};